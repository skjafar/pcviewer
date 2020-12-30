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

    connect(ui->plot, SIGNAL(mouseDoubleClick(QMouseEvent *)), this, SLOT(mouse_doubleclicked(QMouseEvent *)));
    connect(ui->plot, SIGNAL(mousePress(QMouseEvent *)), this, SLOT(mouse_clicked(QMouseEvent *)));
    
    this->loggerStatusChanged();
}

LoggerWindow::~LoggerWindow()
{
    delete ui;
}

void LoggerWindow::loggerStatusChanged()
{
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
    ui->plot->plotLayout()->clear(); // clear default axis rect so we can start from scratch
    connect(block, SIGNAL(onReadDone(Block*,QByteArray)), this, SLOT(onDataRead(Block*,QByteArray)));
    m_loggers.append(block);
    m_names.append(name);
    m_data.append(QByteArray("/null", 1000));
    m_data_sorted.append(QMap<float,float>());
    updateGraph();
}

void LoggerWindow::onIndexRead()
{
    disconnect(m_logIndexRegister, SIGNAL(onReadReply()), ui->plot, SLOT(rescaleAxes()));
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
    
    // dont add to main legand
    ui->plot->setAutoAddPlottableToLegend(false);

    //ui->plot->yAxis->setScaleType(QCPAxis::stLogarithmic);
    ui->plot->setInteractions(QCP::Interaction::iRangeZoom | QCP::Interaction::iRangeDrag | QCP::Interaction::iSelectPlottables);
    //ui->plot->setSelectionRectMode(QCP::srmZoom);
    // create axis rect:
    vector<QCPAxisRect *> loggerAxesRects;
    loggerAxesRects.reserve(m_loggers.size());

    // create vector for sublegands
    vector<QCPLegend *> subLegands;
    subLegands.reserve(m_loggers.size());

    // create a group for aligning the margins
    QCPMarginGroup *marginGroup = new QCPMarginGroup(ui->plot);

    // bring bottom and main axis rect closer together:
    ui->plot->plotLayout()->setRowSpacing(0);

    //configure axis rects and sub-legands
    for (int i = 0; i < m_loggers.size(); i++)
    {
        // create Rect pointer for every log
        loggerAxesRects.push_back(new QCPAxisRect(ui->plot));
        loggerAxesRects[i]->setupFullAxesBox(true);
        loggerAxesRects[i]->axis(QCPAxis::atRight, 0)->setTickLabels(true);
        // add Rect pointer to plot
        ui->plot->plotLayout()->addElement(i, 0, loggerAxesRects[i]);

        // add rect to margin group
        ui->plot->axisRect(i)->setMarginGroup(QCP::msLeft | QCP::msRight, marginGroup);

        //reduce distance between oplots
        ui->plot->axisRect(i)->setAutoMargins(QCP::msLeft|QCP::msRight|QCP::msBottom);
        if (i == 0)
        {
            ui->plot->axisRect(i)->setMargins(QMargins(0, 2, 0, 0));
        }
        else
        {
            ui->plot->axisRect(i)->setMargins(QMargins(0, 0, 0, 0));
        }

        // limit scroll-wheel zoom in horiznotal plane
        ui->plot->axisRect(i)->setRangeZoom(Qt::Horizontal);
        
        // limit selection zoom to vertical plane
        ui->plot->axisRect(i)->setRangeZoomAxes(ui->plot->axisRect(i)->axis(QCPAxis::atBottom), NULL);

        // interconnect x axis ranges of main and bottom axis rects:
        connect(ui->plot->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->plot->axisRect(i)->axis(QCPAxis::atBottom), SLOT(setRange(QCPRange)));
        connect(ui->plot->axisRect(i)->axis(QCPAxis::atBottom), SIGNAL(rangeChanged(QCPRange)), ui->plot->xAxis, SLOT(setRange(QCPRange)));

        //create sub-legand pointer for every plot
        subLegands.push_back(new QCPLegend);
        loggerAxesRects[i]->insetLayout()->addElement(subLegands[i], Qt::AlignTop | Qt::AlignRight);
        subLegands[i]->setLayer("legend");
        subLegands[i]->setBorderPen(QPen(Qt::black));
        subLegands[i]->setBrush(QBrush(Qt::white));
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
        QCPGraph *graph = ui->plot->addGraph(ui->plot->axisRect(i)->axis(QCPAxis::atBottom), ui->plot->axisRect(i)->axis(QCPAxis::atLeft));
        graph->setName(m_names[i]);
        // add to sublegands
        graph->addToLegend(subLegands[i]);
        graph->setPen(QPen(getSequentialColor(i)));


        //if there is no data there is no need to continue
        if (m_data[i].size() == 0) continue;
        
        for (int sample = 0; sample < LOGGER_SAMPLES; sample++)
        {
            float value;
            memcpy(&value, m_data[i].constData() + sample * sizeof(float), sizeof(float));
            
            // shift data according to current index (last stored data) in ring buffer
            float key = (sample < m_index) ?
                LOGGER_SAMPLES - (m_index - sample) :
                sample - m_index;
            // event happens 3/4 on the point line, so offset accordingly, and convert index values to time
            key = (key - LOGGER_SAMPLES * 3 / 4) / SAMPLES_PER_SECOND;
            graph->addData(key, value);

            m_data_sorted[i][key] = value;
        }
        ui->plot->rescaleAxes();
        double range_upper = ui->plot->axisRect(i)->axis(QCPAxis::atLeft)->range().upper;
        double range_lower = ui->plot->axisRect(i)->axis(QCPAxis::atLeft)->range().lower;
        double axisRange   = range_upper - range_lower;
        ui->plot->axisRect(i)->axis(QCPAxis::atLeft)->setRange(range_lower - (axisRange * 0.05), range_upper + (axisRange * 0.05));

    }

    // automatically set range according to data
    ui->plot->rescaleAxes();

    // set range over by a certain percentage
    for (int i = 0; i < m_loggers.size(); i++)
    {
        double range_upper = ui->plot->axisRect(i)->axis(QCPAxis::atLeft)->range().upper;
        double range_lower = ui->plot->axisRect(i)->axis(QCPAxis::atLeft)->range().lower;
        double axisRange   = range_upper - range_lower;
        double added_scale = 0.1;
        ui->plot->axisRect(i)->axis(QCPAxis::atLeft)->setRange(range_lower - (axisRange * added_scale), range_upper + (axisRange * added_scale));
    }
    
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
    QString filepath = QFileDialog::getSaveFileName(this, "Select Folder to Save Log Data To", 
        QDateTime::currentDateTime().toString(QString("yy-MM-dd_hh.mm")) + "_Postmortem_log.dat");

    // create file
    QFile file(filepath);
    if (!file.open(QIODevice::WriteOnly)) return;
    
    QTextStream stream(&file);
    stream << "# Data file generated on " << QDateTime::currentDateTime().toString() << Qt::endl;

    // foreach graph
    int graphIndex;
    for (graphIndex = 0; graphIndex < ui->plot->graphCount(); graphIndex++)
    {
        QCPGraph *graph = ui->plot->graph(graphIndex);

        stream << "#     " << graph->name() << Qt::endl;

        stream << "# Time \t Value" << Qt::endl;

        // get data points
        QSharedPointer<QCPGraphDataContainer> data = graph->data();
        QCPGraphDataContainer::const_iterator it;
        for (it = data->constBegin(); it != data->constEnd(); it++)
        {
            // write to file
            stream << QString::number(it->key) << " \t " << QString::number(it->value) << Qt::endl;
        }
        stream << Qt::endl;
    }
}

void LoggerWindow::mouse_doubleclicked(QMouseEvent *event)
{
    // enforced event by library
    (void)event;

    // reset plot
    ui->plot->rescaleAxes();
    ui->plot->replot();
}

void LoggerWindow::mouse_clicked(QMouseEvent *event)
{
    // zoom with right click and pan with left click
    if (event->buttons() & Qt::RightButton)
    {
        ui->plot->setSelectionRectMode(QCP::srmZoom);
    }
    else if (event->buttons() & Qt::LeftButton)
    {
        ui->plot->setSelectionRectMode(QCP::srmNone);
    }
}
