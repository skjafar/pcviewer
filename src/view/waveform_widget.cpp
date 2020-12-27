#include "waveform_widget.h"
#include "ui_waveform_widget.h"

#include <QDesktopServices>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QDateTime>
#include <QFile>
#include <QUrl>

#include "model/block_request.h"

WaveformWidget::WaveformWidget(QString name, Register *sizeRegister, Register *periodRegister, Register *gainRegister, Register *delayTrigger,
    #ifdef ENABLE_MULTI_ACCESS_RAM_WORKAROUND
                               Register *commandRegister,
    #endif
                               Block *waveformBlock, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WaveformWidget), m_name(name), m_sizeRegister(sizeRegister), m_periodRegister(periodRegister), m_gainRegister(gainRegister), m_delayRegister(delayTrigger),
#ifdef ENABLE_MULTI_ACCESS_RAM_WORKAROUND
    m_commandRegister(commandRegister),
#endif
    m_waveformBlock(waveformBlock)
{
    ui->setupUi(this);

    connect(m_sizeRegister, SIGNAL(onChange()), this, SLOT(onSizeChange()));
    connect(m_periodRegister, SIGNAL(onChange()), this, SLOT(onPeriodChange()));
    connect(m_gainRegister, SIGNAL(onChange()), this, SLOT(onGainChange()));
    connect(m_delayRegister, SIGNAL(onChange()), this, SLOT(onDelayChange()));

    connect(ui->txtSize, SIGNAL(returnPressed()), this, SLOT(changeSize()));
    connect(ui->txtPeriod, SIGNAL(returnPressed()), this, SLOT(changePeriod()));
    connect(ui->txtFinal, SIGNAL(returnPressed()), this, SLOT(changeGain()));
    connect(ui->txtDelay, SIGNAL(returnPressed()), this, SLOT(changeDelay()));

    m_sizeRegister->getPoller(this)->enablePoll(true);
    m_periodRegister->getPoller(this)->enablePoll(true);
    m_gainRegister->getPoller(this)->enablePoll(true);
    m_delayRegister->getPoller(this)->enablePoll(true);

    connect(m_waveformBlock, SIGNAL(onWriteDone(Block*)), this, SLOT(waveformUploaded(Block*)));
    connect(m_waveformBlock, SIGNAL(onError(Block*,request_error_t)), this, SLOT(waveformError(Block*,request_error_t)));

    ui->plot->xAxis->setLabel("Time (sec)");
    ui->plot->yAxis->setLabel("Current (A)");

    onSizeChange();
    onPeriodChange();
    onGainChange();
    onDelayChange();
}

void WaveformWidget::onSizeChange() { ui->lblSize->setText(m_sizeRegister->toString()); }
void WaveformWidget::onPeriodChange() { ui->lblPeriod->setText(m_periodRegister->toString()); }
void WaveformWidget::onGainChange() { ui->lblFinal->setText(m_gainRegister->toString()); }
void WaveformWidget::onDelayChange() { ui->lblDelay->setText(m_delayRegister->toString()); }

void WaveformWidget::changeSize() { m_sizeRegister->write((int32_t) ui->txtSize->text().toLong()); }
void WaveformWidget::changePeriod() { m_periodRegister->write((int32_t) ui->txtPeriod->text().toLong()); }
void WaveformWidget::changeGain() { m_gainRegister->write(ui->txtFinal->text().toFloat()); }
void WaveformWidget::changeDelay() { m_delayRegister->write(ui->txtDelay->text().toInt()); }

void WaveformWidget::plotWaveform(Block *, QByteArray data)
{
    disconnect(m_waveformBlock, SIGNAL(onReadDone(Block*,QByteArray)), this, SLOT(plotWaveform(Block*,QByteArray)));
    accessingRAM(false);

    ui->plot->clearGraphs();
    QCPGraph *graph = ui->plot->addGraph();

    float size = m_sizeRegister->intVal();
    graph->addData(0, data[0]);
    graph->addData(m_delayRegister->floatVal(), data[0]);
    for (int i = 0; i < size; i++)
    {
        float value;
        memcpy(&value, data.constData() + i * sizeof(float), sizeof(float));
        graph->addData((i * m_periodRegister->intVal() * CONTROLLER_PERIOD / 1000) + m_delayRegister->intVal(), value * m_gainRegister->floatVal());
    }

    ui->plot->rescaleAxes();
    ui->plot->replot();
    accessingRAM(true);
}

void WaveformWidget::saveWaveform(Block *, QByteArray data)
{
    disconnect(m_waveformBlock, SIGNAL(onReadDone(Block*,QByteArray)), this, SLOT(saveWaveform(Block*,QByteArray)));
    accessingRAM(false);

    QString filepath = QFileDialog::getSaveFileName(this, "Save Waveform To...", QDateTime::currentDateTime().toString(QString("'%1'_yy-MM-dd_hh-mm-ss").arg(m_name.toLower().replace(" ", ""))), "Waveform Text File (*.*)");
    if (filepath.isEmpty()) return;

    {
        QFile file(filepath);
        if (!file.open(QIODevice::WriteOnly))
        {
            QMessageBox::warning(this, "Waveform Download", "Unable to write to file '" + filepath + "'.");
            return;
        }

        QTextStream stream(&file);

        float size = m_sizeRegister->intVal(); // TODO: decide to save all data or just size data
        for (int i = 0; i < size; i++)
        {
            float value;
            memcpy(&value, data.constData() + i * sizeof(float), sizeof(float));
            stream << value << QT::endl;
        }

        file.close();
    }

    {
        QMessageBox msgbox;
        msgbox.setText("The waveform was saved to '" + filepath + "'");
        msgbox.setInformativeText("Do you want to open the file?");

        QPushButton *openButton = msgbox.addButton("Open", QMessageBox::YesRole);
        msgbox.addButton("Don't Open", QMessageBox::NoRole);

        msgbox.exec();
        if (msgbox.clickedButton() == openButton)
            QDesktopServices::openUrl(QUrl::fromLocalFile(filepath));
    }
}

WaveformWidget::~WaveformWidget()
{
    delete ui;
}

void WaveformWidget::on_btnPlot_clicked()
{
    accessingRAM(false);

    connect(m_waveformBlock, SIGNAL(onReadDone(Block*,QByteArray)), this, SLOT(plotWaveform(Block*,QByteArray)));
    m_waveformBlock->read();
}

void WaveformWidget::on_btnSave_clicked()
{
    accessingRAM(true);

    connect(m_waveformBlock, SIGNAL(onReadDone(Block*,QByteArray)), this, SLOT(saveWaveform(Block*,QByteArray)));
    m_waveformBlock->read();
}

void WaveformWidget::waveformUploaded(Block *)
{
    QMessageBox::information(this, "Waveform Upload", "Waveform uploaded successfully. Re-plotting waveform.");
    connect(m_waveformBlock, SIGNAL(onReadDone(Block*,QByteArray)), this, SLOT(plotWaveform(Block*,QByteArray)));
    m_waveformBlock->read();
}

void WaveformWidget::on_btnUpload_clicked()
{
    QString filepath = QFileDialog::getOpenFileName(this, "Upload Waveform", QString(), "Waveform Text File (*.*)");
    if (filepath.isEmpty()) return;

    accessingRAM(true);

    // load waveform from file
    QFile file(filepath);
    file.open(QIODevice::ReadOnly);

    QTextStream stream(&file);
    QByteArray data;

    QRegExp regexp("\\s+");
    while (!stream.atEnd())
    {
        QString line = stream.readLine();
        QStringList fields = line.split(regexp);

        int i;
        for (i = 0; i < fields.length(); i++)
        {
            float value = fields.at(i).toFloat();
            data.append((char*) &value, sizeof(float));
        }
    }

    m_waveformBlock->write(data);
}

void WaveformWidget::waveformError(Block *, request_error_t errCode)
{
    disconnect(m_waveformBlock, SIGNAL(onReadDone(Block*,QByteArray)), this, SLOT(plotWaveform(Block*,QByteArray)));
    disconnect(m_waveformBlock, SIGNAL(onReadDone(Block*,QByteArray)), this, SLOT(saveWaveform(Block*,QByteArray)));

    accessingRAM(false);

    QMessageBox::warning(this,
        m_name + " Communication Error",
        "A communication error occurred while reading/writing to " + m_name + ".\n"
        "Error code: " + SomeRequest::getErrorDesc(errCode) + " (" + QString::number(errCode) + ")" + "\n"
    );
}

void WaveformWidget::accessingRAM(bool enable)
{
    ui->btnPlot->setEnabled(enable);
    ui->btnSave->setEnabled(enable);
    ui->btnUpload->setEnabled(enable);

#ifdef ENABLE_MULTI_ACCESS_RAM_WORKAROUND
    m_commandRegister->write(enable ? COMMAND_STOP_LOG : COMMAND_START_LOG);
#endif
}
