#include "view/logger_window.h"
#include "ui_logger_window.h"

#include "data/data.h"
#include "common.h"

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
    ui->plot->legend->setVisible(true);
    //ui->plot->yAxis->setScaleType(QCPAxis::stLogarithmic);
    ui->plot->setInteractions(QCP::Interaction::iRangeZoom | QCP::Interaction::iRangeDrag);
    for (int i = 0; i < m_loggers.size(); i++)
    {
        if (m_data[i].size() == 0) continue;

        QCPGraph *graph = ui->plot->addGraph(ui->plot->xAxis, ui->plot->yAxis);

        graph->setName(m_names[i]);
        graph->setPen(QPen(getSequentialColor(i)));

        for (int sample = 0; sample < LOGGER_SAMPLES; sample++)
        {
            float value;
            memcpy(&value, m_data[i].constData() + sample * sizeof(float), sizeof(float));

            float key = (sample < m_index) ?
                LOGGER_SAMPLES - (m_index - sample) :
                sample - m_index;
            graph->addData((key - LOGGER_SAMPLES / 2) / SAMPLES_PER_SECOND, value);
            //graph->addData((sample), value);

        }
    }

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
