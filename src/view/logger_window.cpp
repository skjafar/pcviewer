#include "view/logger_window.h"
#include "ui_logger_window.h"

#include "data/data.h"
#include "common.h"
#include <vector>
using std::vector;

LoggerWindow::LoggerWindow(RegistersMap *registers, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoggerWindow),
    m_loggers(), m_data(), m_names()
{
    ui->setupUi(this);
    ui->plot->xAxis->setLabel("Time");

    m_logIndexRegister = registers->get(LOG_INDEX_REGISTER_NAME);
    Q_ASSERT(m_logIndexRegister != NULL);

    m_loggerStatusRegister = registers->get(LOGGER_STATE_REGISTER_NAME);
    Q_ASSERT(m_loggerStatusRegister != NULL);

    connect(m_loggerStatusRegister, SIGNAL(onChange()), this, SLOT(loggerStatusChanged()));
    m_loggerStatusRegister->getPoller(this)->enablePoll(true);

    m_commandRegister = registers->get(COMMAND_REGISTER_NAME);
    Q_ASSERT(m_commandRegister != NULL);

    this->loggerStatusChanged();
}

LoggerWindow::~LoggerWindow()
{
    delete ui;
}

void LoggerWindow::loggerStatusChanged()
{
    ui->plot->plotLayout()->clear(); // clear default axis rect so we can start from scratch
    if (!m_loggerStatusRegister->valid())
    {
        ui->btnStart->setEnabled(false);
        ui->btnStop->setEnabled(false);
        ui->btnDump->setEnabled(false);
        return;
    }

    switch (m_loggerStatusRegister->intVal())
    {
    case LOGGER_STATE_IDLE:
        ui->btnStart->setEnabled(true);
        ui->btnStop->setEnabled(false);
        ui->btnDump->setEnabled(true);
        break;
    case LOGGER_STATE_ACTIVE:
        ui->btnStart->setEnabled(false);
        ui->btnStop->setEnabled(true);
        ui->btnDump->setEnabled(false);
        break;
    case LOGGER_STATE_POSTMORTEM:
        ui->btnStart->setEnabled(false);
        ui->btnStop->setEnabled(true);
        ui->btnDump->setEnabled(false);
        break;
    case LOGGER_STATE_INTERLOCK:
        ui->btnStart->setEnabled(false);
        ui->btnStop->setEnabled(true);
        ui->btnDump->setEnabled(true);
        break;
    }
}

void LoggerWindow::addLogger(Block *block, QString name)
{
    connect(block, SIGNAL(onReadDone(Block*,QByteArray)), this, SLOT(onDataRead(Block*,QByteArray)));
    m_loggers.append(block);
    m_names.append(name);
    m_data.append(QByteArray());
    m_data_sorted.append(QMap<float,float>());
}

void LoggerWindow::onIndexRead()
{
    disconnect(m_logIndexRegister, SIGNAL(onReadReply()), this, SLOT(onIndexRead()));
    m_index = m_logIndexRegister->uintVal();

    for (int i = 0; i < m_loggers.size(); i++)
    {
        m_data[i].clear();
    }

    m_loggers[0]->read();
}

void LoggerWindow::onDataRead(Block* block, QByteArray data)
{
    // update m_data by finding the index using linear search
    for (int i = 0; i < m_loggers.size(); i++)
    {
        if (m_loggers[i] == block)
        {
            m_data[i] = data;
            if (i + 1 == m_loggers.size()) this->updateGraph();
            else m_loggers[i + 1]->read();

            break;
        }
    }
}

void LoggerWindow::on_btnDump_clicked()
{
    connect(m_logIndexRegister, SIGNAL(onReadReply()), this, SLOT(onIndexRead()));
    m_logIndexRegister->read();
}

void LoggerWindow::updateGraph()
{
    ui->plot->clearGraphs();
    
    //   // create and prepare a text layout element:
    // QCPTextElement *legendTitle = new QCPTextElement(ui->plot);
    // legendTitle->setLayer(ui->plot->legend->layer()); // place text element on same layer as legend, or it ends up below legend
    // legendTitle->setText("Engine Status");
    // legendTitle->setFont(QFont("sans", 9, QFont::Bold));
    // // then we add it to the QCPLegend (which is a subclass of QCPLayoutGrid):
    // if (ui->plot->legend->hasElement(0, 0)) // if top cell isn't empty, insert an empty row at top
    //     ui->plot->legend->insertRow(0);
    // ui->plot->legend->addElement(0, 0, legendTitle); // place the text element into the empty cell
    
    //ui->plot->legend->setVisible(true);
    //ui->plot->yAxis->setScaleType(QCPAxis::stLogarithmic);
    ui->plot->setInteractions(QCP::Interaction::iRangeZoom | QCP::Interaction::iRangeDrag);

    // configure axis rect:
    vector<QCPAxisRect *> loggerAxesRects;
    loggerAxesRects.reserve(m_loggers.size());

    for (int i = 0; i < m_loggers.size(); i++)
    {
        // create Rect pointer for every log
        loggerAxesRects.push_back(new QCPAxisRect(ui->plot));
        loggerAxesRects[i]->setupFullAxesBox(true);
        loggerAxesRects[i]->axis(QCPAxis::atRight, 0)->setTickLabels(true);
        // add Rect pointer to plot
        ui->plot->plotLayout()->addElement(i, 0, loggerAxesRects[i]);
    }
    
    // synchronize the left and right margins of the top and bottom axis rects:
    // move newly created axes on "axes" layer and grids on "grid" layer:
    foreach (QCPAxisRect *rect, ui->plot->axisRects())
    {
        foreach (QCPAxis *axis, rect->axes())
        {
            axis->setLayer("axes");
            axis->grid()->setLayer("grid");
        }
    }
    
    for (int i = 0; i < m_loggers.size(); i++)
    {
        if (m_data[i].size() == 0) continue;

        QCPGraph *graph = ui->plot->addGraph(ui->plot->axisRect(i)->axis(QCPAxis::atBottom), ui->plot->axisRect(i)->axis(QCPAxis::atLeft));

        graph->setName(m_names[i]);
        //graph->setPen(QPen(getSequentialColor(i)));

        for (int sample = 0; sample < LOGGER_SAMPLES; sample++)
        {
            float value;
            memcpy(&value, m_data[i].constData() + sample * sizeof(float), sizeof(float));
            float key = (sample < m_index) ?
                LOGGER_SAMPLES - (m_index - sample) :
                sample - m_index;
            key = (key - LOGGER_SAMPLES * 3 / 4) / SAMPLES_PER_SECOND;
            graph->addData(key, value);
            //graph->addData((sample), value);

            m_data_sorted[i][key] = value;
        }
    }


    //ui->plot->legend->setVisible(true);

    ui->plot->rescaleAxes();
    ui->plot->replot();
}

void LoggerWindow::on_btnStart_clicked()
{
    m_commandRegister->write((uint32_t) COMMAND_START_LOG);
}

void LoggerWindow::on_btnStop_clicked()
{
    m_commandRegister->write((uint32_t) COMMAND_STOP_LOG);
}

void LoggerWindow::on_btnSave_clicked()
{
    QString folder = QFileDialog::getExistingDirectory(this, "Select Folder to Save Data To");
    if (folder.isEmpty()) return;
;
    // for each log
    for (int i = 0; i < m_data_sorted.size(); i++)
    {
        if (m_data_sorted[i].size() == 0) continue;

        // create file
        QString filepath = QDir(folder).filePath(QDateTime::currentDateTime().toString() + "_log.dat");
        QFile file(filepath);
        if (!file.open(QIODevice::WriteOnly)) return;

        QTextStream stream(&file);
        stream << "# Log file generated on " << QDateTime::currentDateTime().toString() << Qt::endl;
        stream << "# " << Qt::endl;
        stream << Qt::endl;
        stream << "# Time \t Value" << Qt::endl;

        // get data points
        QMap<float,float> *data = &m_data_sorted[i];
        QMap<float,float>::ConstIterator it;
        for (it = m_data_sorted[i].constBegin(); it != m_data_sorted[i].constEnd(); it++)
        {
            // write to file
            //stream << QString::number(it->key) << " \t " << QString::number(it->value) << Qt::endl;
        }
    }
}
