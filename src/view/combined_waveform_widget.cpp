#include "combined_waveform_widget.h"
#include "ui_combined_waveform_widget.h"

#include <QDesktopServices>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QDateTime>
#include <QFile>
#include <QUrl>

#include "model/block_request.h"

CombinedWaveformWidget::CombinedWaveformWidget(QString name,
                                               Register *size0Register, Register *period0Register, Register *gain0Register,  Register *delay0Trigger,
                                               Register *size1Register, Register *period1Register, Register *gain1Register,  Register *delay1Trigger,
                                               Register *size2Register, Register *period2Register, Register *gain2Register,  Register *delay2Trigger,
                                               Register *size3Register, Register *period3Register, Register *gain3Register,  Register *delay3Trigger,
    #ifdef ENABLE_MULTI_ACCESS_RAM_WORKAROUND
                               Register *commandRegister,
    #endif
                               Block *waveform0Block, Block *waveform1Block, Block *waveform2Block, Block *waveform3Block, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CombinedWaveformWidget), m_name(name),
                                                m_size0Register(size0Register), m_period0Register(period0Register), m_gain0Register(gain0Register), m_delay0Register(delay0Trigger),
                                                m_size1Register(size1Register), m_period1Register(period1Register), m_gain1Register(gain1Register), m_delay1Register(delay1Trigger),
                                                m_size2Register(size2Register), m_period2Register(period2Register), m_gain2Register(gain2Register), m_delay2Register(delay2Trigger),
                                                m_size3Register(size3Register), m_period3Register(period3Register), m_gain3Register(gain3Register), m_delay3Register(delay3Trigger),
#ifdef ENABLE_MULTI_ACCESS_RAM_WORKAROUND
    m_commandRegister(commandRegister),
#endif
    m_waveform0Block(waveform0Block), m_waveform1Block(waveform1Block), m_waveform2Block(waveform2Block), m_waveform3Block(waveform3Block)
{
    ui->setupUi(this);

    m_size0Register->getPoller(this)->enablePoll(true);
    m_period0Register->getPoller(this)->enablePoll(true);
    m_gain0Register->getPoller(this)->enablePoll(true);
    m_delay0Register->getPoller(this)->enablePoll(true);

    m_size1Register->getPoller(this)->enablePoll(true);
    m_period1Register->getPoller(this)->enablePoll(true);
    m_gain1Register->getPoller(this)->enablePoll(true);
    m_delay1Register->getPoller(this)->enablePoll(true);

    m_size2Register->getPoller(this)->enablePoll(true);
    m_period2Register->getPoller(this)->enablePoll(true);
    m_gain2Register->getPoller(this)->enablePoll(true);
    m_delay2Register->getPoller(this)->enablePoll(true);

    m_size3Register->getPoller(this)->enablePoll(true);
    m_period3Register->getPoller(this)->enablePoll(true);
    m_gain3Register->getPoller(this)->enablePoll(true);
    m_delay3Register->getPoller(this)->enablePoll(true);

    connect(m_waveform0Block, SIGNAL(onError(Block*,request_error_t)), this, SLOT(waveformError(Block*,request_error_t)));
    connect(m_waveform1Block, SIGNAL(onError(Block*,request_error_t)), this, SLOT(waveformError(Block*,request_error_t)));
    connect(m_waveform2Block, SIGNAL(onError(Block*,request_error_t)), this, SLOT(waveformError(Block*,request_error_t)));
    connect(m_waveform3Block, SIGNAL(onError(Block*,request_error_t)), this, SLOT(waveformError(Block*,request_error_t)));


    ui->plot->xAxis->setLabel("Time (sec)");
    ui->plot->yAxis->setLabel("Current (A)");

}


void CombinedWaveformWidget::plotWaveform(Block *, QByteArray data)
{
    //disconnect(m_waveform0Block, SIGNAL(onReadDone(Block*,QByteArray)), this, SLOT(plotWaveform(Block*,QByteArray)));
    //disconnect(m_waveform1Block, SIGNAL(onReadDone(Block*,QByteArray)), this, SLOT(plotWaveform(Block*,QByteArray)));
    //disconnect(m_waveform2Block, SIGNAL(onReadDone(Block*,QByteArray)), this, SLOT(plotWaveform(Block*,QByteArray)));
    //disconnect(m_waveform3Block, SIGNAL(onReadDone(Block*,QByteArray)), this, SLOT(plotWaveform(Block*,QByteArray)));
    accessingRAM(false);

    if (order == 4 or order == 0)
    {
        order = 0;
        lastValue = STANDBY_CURRENT;
        lastTime = 0;
        ui->plot->clearGraphs();
    }


    QCPGraph *graph = ui->plot->addGraph();

    float value;
    float size0 = m_size0Register->intVal();
    float size1 = m_size1Register->intVal();
    float size2 = m_size2Register->intVal();
    float size3 = m_size3Register->intVal();

    switch(order)
    {
    case 0:
        graph->addData(lastTime, lastValue);

        graph->addData(lastTime + m_delay0Register->floatVal(), lastValue);
        for (int i = 0; i < size0; i++)
        {
            memcpy(&value, data.constData() + i * sizeof(float), sizeof(float));
            graph->addData((i * m_period0Register->intVal() * CONTROLLER_PERIOD / 1000) + lastTime + m_delay0Register->intVal(), (value * (m_gain0Register->floatVal() - lastValue)) + lastValue);
        }
        lastValue = (value * (m_gain0Register->floatVal() - lastValue)) + lastValue;
        lastTime = ((size0 - 1) * m_period0Register->intVal() * CONTROLLER_PERIOD / 1000) + lastTime + m_delay0Register->intVal();
        order = 1;
        break;
    case 1:
        graph->addData(lastTime + m_delay1Register->floatVal(), lastValue);
        for (int i = 0; i < size1; i++)
        {
        memcpy(&value, data.constData() + i * sizeof(float), sizeof(float));
        graph->addData((i * m_period1Register->intVal() * CONTROLLER_PERIOD / 1000) + lastTime + m_delay1Register->intVal(), (value * (m_gain1Register->floatVal() - lastValue)) + lastValue);
        }
        lastValue = (value * (m_gain1Register->floatVal() - lastValue)) + lastValue;
        lastTime = ((size1 - 1) * m_period1Register->intVal() * CONTROLLER_PERIOD / 1000) + lastTime + m_delay1Register->intVal();
        order = 2;
        break;
    case 2:
        graph->addData(lastTime + m_delay2Register->floatVal(), lastValue);
        for (int i = 0; i < size2; i++)
        {
            memcpy(&value, data.constData() + i * sizeof(float), sizeof(float));
            graph->addData((i * m_period2Register->intVal() * CONTROLLER_PERIOD / 1000) + lastTime + m_delay2Register->intVal(), (value * (m_gain2Register->floatVal() - lastValue)) + lastValue);
        }
        lastValue = (value * (m_gain2Register->floatVal() - lastValue)) + lastValue;
        lastTime = ((size2 - 1) * m_period2Register->intVal() * CONTROLLER_PERIOD / 1000) + lastTime + m_delay2Register->intVal();
        order = 3;
        break;
    case 3:
        graph->addData(lastTime + m_delay3Register->floatVal(), lastValue);
        for (int i = 0; i < size3; i++)
        {
            memcpy(&value, data.constData() + i * sizeof(float), sizeof(float));
            graph->addData((i * m_period3Register->intVal() * CONTROLLER_PERIOD / 1000) + lastTime + m_delay3Register->intVal(), (value * (m_gain3Register->floatVal() - lastValue)) + lastValue);
        }
        lastValue = (value * (m_gain3Register->floatVal() - lastValue)) + lastValue;
        lastTime = ((size3 - 1) * m_period3Register->intVal() * CONTROLLER_PERIOD / 1000) + lastTime + m_delay3Register->intVal();
        order = 4;\
        accessingRAM(true);
        break;
    default:
        break;
    }

    ui->plot->rescaleAxes();
    ui->plot->replot();

}

CombinedWaveformWidget::~CombinedWaveformWidget()
{
    delete ui;
}

void CombinedWaveformWidget::on_btnPlot_clicked()
{
    accessingRAM(false);

    connect(m_waveform0Block, SIGNAL(onReadDone(Block*,QByteArray)), this, SLOT(plotWaveform(Block*, QByteArray)));
    connect(m_waveform1Block, SIGNAL(onReadDone(Block*,QByteArray)), this, SLOT(plotWaveform(Block*, QByteArray)));
    connect(m_waveform2Block, SIGNAL(onReadDone(Block*,QByteArray)), this, SLOT(plotWaveform(Block*, QByteArray)));
    connect(m_waveform3Block, SIGNAL(onReadDone(Block*,QByteArray)), this, SLOT(plotWaveform(Block*, QByteArray)));
    m_waveform0Block->read();

    m_waveform1Block->read();

    m_waveform2Block->read();

    m_waveform3Block->read();
}

void CombinedWaveformWidget::waveformError(Block *, request_error_t errCode)
{
    disconnect(m_waveform0Block, SIGNAL(onReadDone(Block*,QByteArray)), this, SLOT(plotWaveform(Block*,QByteArray)));
    disconnect(m_waveform1Block, SIGNAL(onReadDone(Block*,QByteArray)), this, SLOT(plotWaveform(Block*,QByteArray)));
    disconnect(m_waveform2Block, SIGNAL(onReadDone(Block*,QByteArray)), this, SLOT(plotWaveform(Block*,QByteArray)));
    disconnect(m_waveform3Block, SIGNAL(onReadDone(Block*,QByteArray)), this, SLOT(plotWaveform(Block*,QByteArray)));

    accessingRAM(false);

    QMessageBox::warning(this,
        m_name + " Communication Error",
        "A communication error occurred while reading/writing to " + m_name + ".\n"
        "Error code: " + SomeRequest::getErrorDesc(errCode) + " (" + QString::number(errCode) + ")" + "\n"
    );
}

void CombinedWaveformWidget::accessingRAM(bool enable)
{
    ui->btnPlot->setEnabled(enable);

#ifdef ENABLE_MULTI_ACCESS_RAM_WORKAROUND
    m_commandRegister->write(enable ? COMMAND_STOP_LOG : COMMAND_START_LOG);
#endif
}
