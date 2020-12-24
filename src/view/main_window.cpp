#include "view/main_window.h"
#include "ui_main_window.h"

#include <QDesktopServices>
#include <QFileDialog>
#include <QMessageBox>
#include <QDateTime>
#include <QLineEdit>
#include <QUrl>
#include <QDebug>

#include "view/registers_window.h"
#include "view/register_widget.h"
#include "view/waveforms_window.h"
#include "view/plotter_window.h"
#include "view/faults_window.h"
#include "view/logger_window.h"
#include "view/dpc_faults_window.h"
#include "view/about_window.h"

#include "model/register_request.h"
#include "build_number.h"
#include "data/data.h"

MainWindow::MainWindow(RegistersMap *registers, BlocksMap *blocks, FaultsMap *faults, DevicesMap *devices, ParameterDefinitions *parameterSetDefinitions, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), m_registers(registers), m_blocks(blocks), m_faults(faults), m_devices(devices), m_parameterSetDefinitions(parameterSetDefinitions)
{
    ui->setupUi(this);

//	// setup ID
//    this->setWindowTitle("DPC_CC_ID " + QString::number(registers->get("DPC_CC_ID")->uintVal()));

    // setup toolbar
    lblPriority = new QLabel(this);
    ui->stbMain->addPermanentWidget(lblPriority);
    lblPriority->setText("Priority undecided");

    lblStatus = new QLabel(this);
    ui->stbMain->addWidget(lblStatus);
    lblStatus->setText("");

    // global state machine setup
    m_globalStateMachine = new GlobalStateMachine(
        registers->get(GLOBAL_STATE_MACHINE_REGISTER_NAME),
        registers->get(SEQUENCER_STATE_MACHINE_REGISTER_NAME),
        registers->get(COMMAND_REGISTER_NAME),
        this
    );
    connect(m_globalStateMachine, SIGNAL(afterStateChange()), this, SLOT(onStateChanged()));
    onStateChanged();
    m_stateRegister = registers->get("STATE_HANDLER");
    m_stateRegister->getPoller(this)->enablePoll(true);

	// Reference current setup
    m_referenceCurrentRegister = registers->get(REFERENCE_REGISTER_NAME);
    m_referenceCurrentRegister->getPoller(this)->enablePoll(true);
    connect(m_referenceCurrentRegister, SIGNAL(onChange()), this, SLOT(onReferenceCurrentChanged()));
    onReferenceCurrentChanged();


//    // Measurement setup
//    m_IloadRegister = registers->get("ILOAD");
//    m_IloadRegister->getPoller(this)->enablePoll(true);
//    connect(m_IloadRegister, SIGNAL(onChange()), this, SLOT(onIloadChanged()));
//    onIloadChanged();

    // priority setup
    m_priorityRegister = registers->get(SYSTEM_PRIORITY_REGISTER_NAME);
    m_priorityRegister->getPoller(this)->enablePoll(true);
    connect(m_priorityRegister, SIGNAL(onChange()), this, SLOT(onWriteEnableChanged()));
    connect(ui->actionSettingsEnableWrites, SIGNAL(triggered()), this, SLOT(onWriteEnableChanged()));
    onWriteEnableChanged();

    // next waveform setup
    m_nextWaveformRegister = registers->get(WAVEFORM_NEXT_REGISTER_NAME);
    m_nextWaveformRegister->getPoller(this)->enablePoll(true);
    connect(m_nextWaveformRegister, SIGNAL(onChange()), this, SLOT(onNextWaveformChanged()));
    onNextWaveformChanged();

    // parameterization setup
    Block *block = blocks->get(PARAMETER_SET_1_BLOCK_NAME);
    connect(block, SIGNAL(onReadDone(Block*,QByteArray)), this, SLOT(onParameterSetReadDone(Block*,QByteArray)));
    connect(block, SIGNAL(onWriteDone(Block*)), this, SLOT(onParameterSetWriteDone(Block*)));
    connect(block, SIGNAL(onError(Block*,request_error_t)), this, SLOT(onParameterSetCommError(Block*,request_error_t)));

    block = blocks->get(DSP_FIRMWARE_BLOCK_NAME);
    connect(block, SIGNAL(onWriteDone(Block*)), this, SLOT(onDSPFlashDone(Block*)));
    connect(block, SIGNAL(onError(Block*,request_error_t)), this, SLOT(onDSPFlashError(Block*,request_error_t)));


    // title bar setup  (Sofian)
    m_DPC_CC_IDRegister = registers->get(DPC_CC_ID_REGISTER_NAME);
    m_DPC_CC_IDRegister->getPoller(this)->enablePoll(true);
    connect(m_DPC_CC_IDRegister, SIGNAL(onChange()), this, SLOT(onIDChanged()));
    onIDChanged();

    // ILOAD setup (Sofian)
    m_ILOADRegister = registers->get(ILOAD_REGISTER_NAME);
    m_ILOADRegister->getPoller(this)->enablePoll(true);
    connect(m_ILOADRegister, SIGNAL(onChange()), this, SLOT(onILOADChanged()));
    onILOADChanged();
}

MainWindow::~MainWindow()
{
    enableWrite(false);
    delete ui;
}

void MainWindow::enableWrite(bool enable)
{
    if (enable && m_priorityRegister->uintVal() != ETHERNET_PRIORITIZED)
        m_priorityRegister->write(0x1000000); // MAGIC!
    else if (!enable && m_priorityRegister->uintVal() == ETHERNET_PRIORITIZED)
        m_priorityRegister->write(0x0);
}

void MainWindow::onWriteEnableChanged()
{
    if (!m_priorityRegister->valid())
    {
        lblPriority->setText("Priority undecided");
        return;
    }

    lblPriority->setText(
        m_priorityRegister->uintVal() == ETHERNET_PRIORITIZED ?
            "Ethernet prioritized (writes enabled)" :
            "Not ethernet prioritized (writes disabled)"
    );

    if (ui->actionSettingsEnableWrites->isChecked() && m_priorityRegister->uintVal() != ETHERNET_PRIORITIZED)
        this->enableWrite(true);
    else if (!ui->actionSettingsEnableWrites->isChecked() && m_priorityRegister->uintVal() == ETHERNET_PRIORITIZED)
        this->enableWrite(false);
}

void MainWindow::onReferenceCurrentChanged()
{
    if (m_referenceCurrentRegister->valid())
        ui->lblReferenceCurrent->setText(QString::number(m_referenceCurrentRegister->floatVal(), 'f', 3) + ((m_globalStateMachine->currentState() == GLOBAL_STATE_OPENLOOP) ? " V" : " A"));
    else
        ui->lblReferenceCurrent->setText("N/A");
}

void MainWindow::onNextWaveformChanged()
{
    if (m_nextWaveformRegister->valid())
        ui->lblNextWaveform->setText("Waveform " + QString::number(m_nextWaveformRegister->intVal()));
    else
        ui->lblNextWaveform->setText("N/A");
}

void MainWindow::on_btnOff_clicked()
{
    m_globalStateMachine->setState(GLOBAL_STATE_OFF);
}

void MainWindow::on_btnStandby_clicked()
{
    m_globalStateMachine->setState(GLOBAL_STATE_STANDBY);
}

void MainWindow::on_btnON_clicked()
{
    m_globalStateMachine->setState(GLOBAL_STATE_ON);
}

void MainWindow::on_btnReset_clicked()
{
    m_globalStateMachine->resetInterlocks();
}

void MainWindow::on_btnOpenloop_clicked()
{
    m_globalStateMachine->setState(GLOBAL_STATE_OPENLOOP);
}

void MainWindow::onStateChanged()
{
    switch (m_globalStateMachine->currentState())
    {
    case GLOBAL_STATE_OFF:
        ui->btnOff->setChecked(true);
        ui->btnOff->setEnabled(false);

        ui->btnStandby->setChecked(false);
        ui->btnStandby->setEnabled(true);

        ui->btnON->setChecked(false);
        ui->btnON->setEnabled(false);

        ui->btnOpenloop->setChecked(false);
        ui->btnOpenloop->setEnabled(true);

        ui->btnReset->setEnabled(false);
        ui->btnSendInterlock->setEnabled(true);
        ui->lblInterlockLED->setPixmap(QPixmap(":/resources/images/red-off.png"));

        ui->lblState->setText("OFF");
        break;
    case GLOBAL_STATE_STANDBY:
        ui->btnOff->setChecked(false);
        ui->btnOff->setEnabled(true);

        ui->btnStandby->setChecked(true);
        ui->btnStandby->setEnabled(false);

        ui->btnON->setChecked(false);
        ui->btnON->setEnabled(true);

        ui->btnOpenloop->setChecked(false);
        ui->btnOpenloop->setEnabled(true);

        ui->btnReset->setEnabled(false);
        ui->btnSendInterlock->setEnabled(true);
        ui->lblInterlockLED->setPixmap(QPixmap(":/resources/images/red-off.png"));

        ui->lblState->setText("STANDBY");
        break;
    case GLOBAL_STATE_ON:
        ui->btnOff->setChecked(false);
        ui->btnOff->setEnabled(false);

        ui->btnStandby->setChecked(false);
        ui->btnStandby->setEnabled(true);

        ui->btnON->setChecked(true);
        ui->btnON->setEnabled(false);

        ui->btnOpenloop->setChecked(false);
        ui->btnOpenloop->setEnabled(false);

        ui->btnReset->setEnabled(false);
        ui->btnSendInterlock->setEnabled(true);
        ui->lblInterlockLED->setPixmap(QPixmap(":/resources/images/red-off.png"));

        ui->lblState->setText("ON");
        break;
    case GLOBAL_STATE_FAULT:
        ui->btnOff->setChecked(false);
        ui->btnOff->setEnabled(false);

        ui->btnStandby->setChecked(false);
        ui->btnStandby->setEnabled(false);

        ui->btnON->setChecked(false);
        ui->btnON->setEnabled(false);

        ui->btnOpenloop->setChecked(false);
        ui->btnOpenloop->setEnabled(false);

        ui->btnReset->setEnabled(true);
        ui->btnSendInterlock->setEnabled(false);
        ui->lblInterlockLED->setPixmap(QPixmap(":/resources/images/red-on.png"));

        ui->lblState->setText("FAULT");
        break;
    case GLOBAL_STATE_OPENLOOP:
        ui->btnOff->setChecked(false);
        ui->btnOff->setEnabled(true);

        ui->btnStandby->setChecked(false);
        ui->btnStandby->setEnabled(true);

        ui->btnON->setChecked(false);
        ui->btnON->setEnabled(false);

        ui->btnOpenloop->setChecked(true);
        ui->btnOpenloop->setEnabled(false);

        ui->btnReset->setEnabled(false);
        ui->btnSendInterlock->setEnabled(true);
        ui->lblInterlockLED->setPixmap(QPixmap(":/resources/images/red-off.png"));

        ui->lblState->setText("OPENLOOP");
        break;
    case GLOBAL_STATE_REPLY:
        ui->btnOff->setChecked(true);
        ui->btnOff->setEnabled(true);

        ui->btnStandby->setChecked(true);
        ui->btnStandby->setEnabled(true);

        ui->btnON->setChecked(true);
        ui->btnON->setEnabled(true);

        ui->btnOpenloop->setChecked(true);
        ui->btnOpenloop->setEnabled(true);

        ui->btnReset->setEnabled(true);
        ui->btnSendInterlock->setEnabled(true);
        ui->lblInterlockLED->setPixmap(QPixmap(":/resources/images/red-off.png"));

        ui->lblState->setText("REPLY");
        break;
    default:
        qWarning("Reached unhandled state (state = %d)", m_globalStateMachine->currentState());
        ui->btnOff->setChecked(false);
        ui->btnStandby->setChecked(false);
        ui->btnON->setChecked(false);
        ui->btnOpenloop->setChecked(false);

        ui->btnOff->setEnabled(false);
        ui->btnStandby->setEnabled(false);
        ui->btnON->setEnabled(false);
        ui->btnOpenloop->setEnabled(false);
        ui->btnReset->setEnabled(false);
        ui->btnSendInterlock->setEnabled(false);

        ui->lblInterlockLED->setPixmap(QPixmap(":/resources/images/red-off.png"));

        ui->lblState->setText("INVALID");
        break;
    }

    switch (m_globalStateMachine->currentSequencerState())
    {
    case SEQ_STATE_DC:
    case SEQ_STATE_IDLE:
        ui->btnSkip->setEnabled(false);
        ui->btnTrigger->setEnabled(false);
        ui->btnPause->setEnabled(false);
        ui->btnResume->setEnabled(false);
        ui->btnStop->setEnabled(false);

        ui->btnSemiAutomatic->setEnabled(false);
        ui->btnAutomatic->setEnabled(false);
        ui->btnManual->setEnabled(false);
        break;
    case SEQ_STATE_ARMED:
        ui->btnSkip->setEnabled(false);
        ui->btnTrigger->setEnabled(false);
        ui->btnPause->setEnabled(false);
        ui->btnResume->setEnabled(false);
        ui->btnStop->setEnabled(true);

        ui->btnSemiAutomatic->setEnabled(true);
        ui->btnAutomatic->setEnabled(true);
        ui->btnManual->setEnabled(true);
        break;
    case SEQ_STATE_MANUAL:
    case SEQ_STATE_AUTO:
    case SEQ_STATE_SEMIAUTO:
        ui->btnSkip->setEnabled(true);
        ui->btnTrigger->setEnabled(m_globalStateMachine->currentSequencerState() == SEQ_STATE_MANUAL || m_globalStateMachine->currentSequencerState() == SEQ_STATE_SEMIAUTO);
        ui->btnPause->setEnabled(false);
        ui->btnResume->setEnabled(false);
        ui->btnStop->setEnabled(true);

        ui->btnSemiAutomatic->setEnabled(false);
        ui->btnAutomatic->setEnabled(false);
        ui->btnManual->setEnabled(false);
        break;
    case SEQ_STATE_SEMIAUTO_ACTIVE:
    case SEQ_STATE_AUTO_ACTIVE:
    case SEQ_STATE_MANUAL_ACTIVE:
        ui->btnSkip->setEnabled(false);
        ui->btnTrigger->setEnabled(false);
        ui->btnPause->setEnabled(true);
        ui->btnResume->setEnabled(true);
        ui->btnStop->setEnabled(true);

        ui->btnSemiAutomatic->setEnabled(false);
        ui->btnAutomatic->setEnabled(false);
        ui->btnManual->setEnabled(false);
        break;
    }
}

void MainWindow::on_btnPause_clicked()
{
    m_globalStateMachine->sendCommand(COMMAND_PAUSE);
}

void MainWindow::on_btnTrigger_clicked()
{
    m_globalStateMachine->sendCommand(COMMAND_TRIGGER);
}

void MainWindow::on_btnResume_clicked()
{
    m_globalStateMachine->sendCommand(COMMAND_RESUME);
}

void MainWindow::on_btnStop_clicked()
{
    m_globalStateMachine->sendCommand(COMMAND_STOP);
}

void MainWindow::on_btnSemiAutomatic_clicked()
{
    m_globalStateMachine->sendCommand(COMMAND_SEMIAUTO);
}

void MainWindow::on_btnAutomatic_clicked()
{
    m_globalStateMachine->sendCommand(COMMAND_AUTO);
}

void MainWindow::on_btnManual_clicked()
{
    m_globalStateMachine->sendCommand(COMMAND_MANUAL);
}

void MainWindow::on_btnSendInterlock_clicked()
{
    m_globalStateMachine->sendCommand(COMMAND_FAULT);
}

void MainWindow::on_btnSkip_clicked()
{
    m_globalStateMachine->sendCommand(COMMAND_NEXT);
}

void MainWindow::on_txtReferenceCurrent_returnPressed()
{
    m_referenceCurrentRegister->write(ui->txtReferenceCurrent->text().toFloat());
}

void MainWindow::onParameterSetCommError(Block*, request_error_t)
{
    // TODO: restart logger in case of write error?
    lblStatus->setText("");
    ui->stbMain->showMessage("Communication failure with DPC for uploading/downloading parameter sets.", 5000);
    QMessageBox::warning(this, "Parameter Set", "A communication failure occurred during uploading/downloading the parameters set.");
}

void MainWindow::on_btnWaveformSettings_clicked()
{
    WaveformsWindow *window = new WaveformsWindow(m_registers, m_blocks);
    window->show();
    onIDChanged();
}

void MainWindow::on_actionWaveformSettings_triggered()
{
    WaveformsWindow *window = new WaveformsWindow(m_registers, m_blocks);
    window->show();
    onIDChanged();
}

void MainWindow::on_actionLoggerShow_triggered()
{
    LoggerWindow *loggerWindow = new LoggerWindow(m_registers, this);
    loggerWindow->addLogger(m_blocks->get("IREF log"), "IREF");
    loggerWindow->addLogger(m_blocks->get("ILOAD log"), "ILOAD");
    loggerWindow->addLogger(m_blocks->get("VMON log"), "VMON");
   loggerWindow->addLogger(m_blocks->get("FAULTS log"), "FAULTS");
   loggerWindow->addLogger(m_blocks->get("PCO_FAULTS log"), "PCO_FAULTS");
   loggerWindow->addLogger(m_blocks->get("STATE log"), "STATE");
    loggerWindow->show();
    onIDChanged();
}

void MainWindow::on_actionParameterizationDownload_triggered()
{
#ifdef ENABLE_MULTI_ACCESS_RAM_WORKAROUND
    // stop logger
    m_registers->get(COMMAND_REGISTER_NAME)->write(COMMAND_STOP_LOG);
#endif

    Block *block = m_blocks->get(PARAMETER_SET_1_BLOCK_NAME);
    block->read();
    lblStatus->setText("Loading parameter set from DPC...");
}

void MainWindow::on_actionPlotterShow_triggered()
{
    PlotterWindow *window = new PlotterWindow(m_registers, this);
    window->show();
    onIDChanged();
}

void MainWindow::on_actionTest_triggered()
{
    RegistersWindow	*window	= 	new RegistersWindow	(m_registers, this);

	window->insertSplitter("Setters");

	RegisterWidget	*widget;
    widget 	= 	new RegisterWidget	(m_registers, m_registers->get("COMMAND"), this);
    window->insertWidget(widget);
    widget 	= 	new RegisterWidget	(m_registers, m_registers->get("SLOW_OUTPUTS"), this);
    window->insertWidget(widget);
    widget 	= 	new RegisterWidget	(m_registers, m_registers->get("DAC_REFERENCE"), this);
    window->insertWidget(widget);

	window->insertSplitter("Getters");

    widget	= 	new RegisterWidget	(m_registers, m_registers->get("FIRMWARE_VERSION"), this);
    window->insertWidget(widget);
    widget 	= 	new RegisterWidget	(m_registers, m_registers->get("FIRMWARE_REVISION"), this);
    window->insertWidget(widget);
    widget	= 	new RegisterWidget	(m_registers, m_registers->get("STATE_HANDLER"), this);
    window->insertWidget(widget);
    widget	= 	new RegisterWidget	(m_registers, m_registers->get("SLOW_INPUTS"), this);
    window->insertWidget(widget);
    widget 	= 	new RegisterWidget	(m_registers, m_registers->get("WARNINGS"), this);
    window->insertWidget(widget);
    widget 	= 	new RegisterWidget	(m_registers, m_registers->get("TEMPERATURE_CC"), this);
    window->insertWidget(widget);
    widget 	= 	new RegisterWidget	(m_registers, m_registers->get("TEMPERATURE_IDAC"), this);
    window->insertWidget(widget);
    widget 	= 	new RegisterWidget	(m_registers, m_registers->get("ADC_A0"), this);
    window->insertWidget(widget);
    widget 	= 	new RegisterWidget	(m_registers, m_registers->get("ADC_A1"), this);
    window->insertWidget(widget);
    widget 	= 	new RegisterWidget	(m_registers, m_registers->get("ADC_C0"), this);
    window->insertWidget(widget);
    widget 	= 	new RegisterWidget	(m_registers, m_registers->get("ADC_C1"), this);
    window->insertWidget(widget);

    window->insertSplitter("Extras");

    widget 	= 	new RegisterWidget	(m_registers, this);
    window->insertWidget(widget);

    window->show();
    onIDChanged();
}

void MainWindow::on_actionStates_triggered()
{
    RegistersWindow	*window	= 	new RegistersWindow	(m_registers, this);

	window->insertSplitter("States");

	RegisterWidget	*widget;
    widget 	= 	new RegisterWidget	(m_registers, m_registers->get("STATE_TIA"), this);
    window->insertWidget(widget);
    widget 	= 	new RegisterWidget	(m_registers, m_registers->get("STATE_PCO"), this);
    window->insertWidget(widget);
    widget 	= 	new RegisterWidget	(m_registers, m_registers->get("STATE_OFF"), this);
    window->insertWidget(widget);
    widget 	= 	new RegisterWidget	(m_registers, m_registers->get("STATE_STANDBY"), this);
    window->insertWidget(widget);
    widget 	= 	new RegisterWidget	(m_registers, m_registers->get("STATE_ON"), this);
    window->insertWidget(widget);
    widget 	= 	new RegisterWidget	(m_registers, m_registers->get("STATE_FAULT"), this);
    window->insertWidget(widget);
    widget 	= 	new RegisterWidget	(m_registers, m_registers->get("STATE_SYNCHRONIZER"), this);
    window->insertWidget(widget);
    widget 	= 	new RegisterWidget	(m_registers, m_registers->get("STATE_HANDLER"), this);
    window->insertWidget(widget);
    widget 	= 	new RegisterWidget	(m_registers, m_registers->get("STATE_SEQUENCER"), this);
    window->insertWidget(widget);
    widget 	= 	new RegisterWidget	(m_registers, m_registers->get("STATE_PLAYER"), this);
    window->insertWidget(widget);
    widget 	= 	new RegisterWidget	(m_registers, m_registers->get("STATE_LOGGER"), this);
    window->insertWidget(widget);
    widget 	= 	new RegisterWidget	(m_registers, m_registers->get("STATE_TERMINAL"), this);
    window->insertWidget(widget);

	window->insertSplitter("Errors");

    widget 	= 	new RegisterWidget	(m_registers, m_registers->get("FAULTS"), this);
    window->insertWidget(widget);
    widget 	= 	new RegisterWidget	(m_registers, m_registers->get("PCO_FAULTS"), this);
    window->insertWidget(widget);
    widget 	= 	new RegisterWidget	(m_registers, m_registers->get("FIRST_FAULT"), this);
    window->insertWidget(widget);
    widget 	= 	new RegisterWidget	(m_registers, m_registers->get("WARNINGS"), this);
    window->insertWidget(widget);

	window->insertSplitter("Extras");

    widget 	= 	new RegisterWidget	(m_registers, this);
    window->insertWidget(widget);

    window->show();
    onIDChanged();
}

void MainWindow::on_actionTune_triggered()
{
    RegistersWindow	*window	= 	new RegistersWindow	(m_registers, this);

	window->insertSplitter("Process");

	RegisterWidget	*widget;
    widget 	= 	new RegisterWidget	(m_registers, m_registers->get("KP"), this);
    window->insertWidget(widget);
    widget 	= 	new RegisterWidget	(m_registers, m_registers->get("KI"), this);
    window->insertWidget(widget);
    widget 	= 	new RegisterWidget	(m_registers, m_registers->get("I2V_GAIN"), this);
    window->insertWidget(widget);
    widget 	= 	new RegisterWidget	(m_registers, m_registers->get("OFFSET_ERROR"), this);
    window->insertWidget(widget);
    widget 	= 	new RegisterWidget	(m_registers, m_registers->get("GAIN_ERROR"), this);
    window->insertWidget(widget);
    widget 	= 	new RegisterWidget	(m_registers, m_registers->get("MAX_IREF"), this);
    window->insertWidget(widget);
    widget 	= 	new RegisterWidget	(m_registers, m_registers->get("MIN_IREF"), this);
    window->insertWidget(widget);
    widget 	= 	new RegisterWidget	(m_registers, m_registers->get("MAX_dIdt"), this);
    window->insertWidget(widget);
    widget 	= 	new RegisterWidget	(m_registers, m_registers->get("MIN_dIdt"), this);
    window->insertWidget(widget);
    widget 	= 	new RegisterWidget	(m_registers, m_registers->get("MAX_ETOTAL"), this);
    window->insertWidget(widget);
    widget 	= 	new RegisterWidget	(m_registers, m_registers->get("MIN_ETOTAL"), this);
    window->insertWidget(widget);
    widget 	= 	new RegisterWidget	(m_registers, m_registers->get("MAX_PCO_VOUT"), this);
    window->insertWidget(widget);
    widget 	= 	new RegisterWidget	(m_registers, m_registers->get("MAX_PCO_IOUT"), this);
    window->insertWidget(widget);

	window->insertSplitter("Interlocks");

    widget 	= 	new RegisterWidget	(m_registers, m_registers->get("INTERLOCK_VMON"), this);
    window->insertWidget(widget);
    widget 	= 	new RegisterWidget	(m_registers, m_registers->get("INTERLOCK_ILOAD"), this);
    window->insertWidget(widget);
    widget 	= 	new RegisterWidget	(m_registers, m_registers->get("INTERLOCK_IEARTH"), this);
    window->insertWidget(widget);
    widget 	= 	new RegisterWidget	(m_registers, m_registers->get("INTERLOCK_dIdt"), this);
    window->insertWidget(widget);
    widget 	= 	new RegisterWidget	(m_registers, m_registers->get("INTERLOCK_ERROR"), this);
    window->insertWidget(widget);
    widget 	= 	new RegisterWidget	(m_registers, m_registers->get("INTERLOCK_TEMPERATURE"), this);
    window->insertWidget(widget);

	window->insertSplitter("Extras");

    widget 	= 	new RegisterWidget	(m_registers, this);
    window->insertWidget(widget);

    window->show();
    onIDChanged();
}

void MainWindow::on_actionRawRegistersShow_triggered()
{
    RegistersWindow *window = new RegistersWindow(m_registers, this);

    RegisterWidget	*widget;
    widget 	= 	new RegisterWidget	(m_registers, m_registers->get("FAULTS"), this);
    window->insertWidget(widget);

    window->show();
    onIDChanged();
}

void MainWindow::on_actionDPCFaultsShow_triggered()
{
    DPC_FAULTS_WINDOW *window = new DPC_FAULTS_WINDOW(m_registers, this);
    window->show();
    onIDChanged();
}

void MainWindow::on_actionFaultsShow_triggered()
{
    FaultsWindow *window = new FaultsWindow(m_registers, m_faults, this);
    window->show();
    onIDChanged();
}

void MainWindow::on_actionAbout_triggered()
{
    AboutWindow *window = new AboutWindow(this);
    window->show();
    onIDChanged();
}

void MainWindow::on_actionParameterizationUpload_triggered()
{
    QString filepath = QFileDialog::getOpenFileName(this, "Load Parameter Set From...", QString(), "Parameter File (*.pf)");
    if (filepath.isEmpty()) return;

    ParameterSet set(m_parameterSetDefinitions);
    bool loaded = set.loadFromFile(filepath);
    if (!loaded)
    {
        QMessageBox::warning(this, "Parameter Set File", "Unable to load parameter set from file. Aborting operation.");
        return;
    }

#ifdef ENABLE_MULTI_ACCESS_RAM_WORKAROUND
    // stop logger
    m_registers->get(COMMAND_REGISTER_NAME)->write(COMMAND_STOP_LOG);
#endif

    Block *block = m_blocks->get(PARAMETER_SET_1_BLOCK_NAME);
    set.saveToBlock(block);
    lblStatus->setText("Flashing parameter set...");
}

void MainWindow::onParameterSetWriteDone(Block *)
{
#ifdef ENABLE_MULTI_ACCESS_RAM_WORKAROUND
    // restart logger
    m_registers->get(COMMAND_REGISTER_NAME)->write(COMMAND_START_LOG);
#endif

    lblStatus->setText("");
    QMessageBox::information(this, "Parameter Set Flash", "Flash completed successfully.");
}

void MainWindow::onParameterSetReadDone(Block *, QByteArray data)
{
#ifdef ENABLE_MULTI_ACCESS_RAM_WORKAROUND
    // restart logger
    m_registers->get(COMMAND_REGISTER_NAME)->write(COMMAND_START_LOG);
#endif

    lblStatus->setText("");
    ParameterSet *set = new ParameterSet(m_parameterSetDefinitions, this);
    if (set->loadFromBlockArray(data))
    {
        QString filepath = QFileDialog::getSaveFileName(this, "Save Parameter Set To...", QDateTime::currentDateTime().toString("'parameters-'yy-MM-dd_hh-mm-ss.pf"), "Parameter File (*.pf)");
        if (filepath.isEmpty()) return;
        set->saveToFile(filepath);

        {
            QMessageBox msgbox;
            msgbox.setText("The parameters set was saved to '" + filepath + "'");
            msgbox.setInformativeText("Do you want to open the file?");

            QPushButton *openButton = msgbox.addButton("Open", QMessageBox::YesRole);
            msgbox.addButton("Don't Open", QMessageBox::NoRole);

            msgbox.exec();
            if (msgbox.clickedButton() == openButton)
                QDesktopServices::openUrl(QUrl::fromLocalFile(filepath));
        }
    }
    else
    {
        ui->stbMain->showMessage("Failed to load parameter set.", 5000);
        QMessageBox::warning(this, "Parameter Set", "Failed to load parameter set.");
    }
}

void MainWindow::on_actionRestartFirmware_triggered()
{
    if (QMessageBox::question(this, "Firmware Restart", "Are you sure you want to restart the firmware?", QMessageBox::Yes, QMessageBox::No) == QMessageBox::Yes)
    {
        Register *systemOperatingStateRegister = m_registers->get(SYSTEM_OPERATING_STATE_REGISTER_NAME);

        // RegisterRequest is used so that only one callback is received when a read to that register occurs
        RegisterRequest *request = new RegisterRequest(RegisterRequestType_Read, systemOperatingStateRegister->address(), this);
        connect(request, SIGNAL(onReadDone(RegisterRequest*)), this, SLOT(onSystemOperatingStateRead(RegisterRequest*)));
        connect(request, SIGNAL(onError(RegisterRequest*,request_error_t)), this, SLOT(onSystemOperatingStateError(RegisterRequest*,request_error_t)));

        ui->stbMain->showMessage("Checking system state...");
        systemOperatingStateRegister->communicator()->queueRequest(request);
    }
}

void MainWindow::onSystemOperatingStateRead(RegisterRequest* request)
{
    if (request->intVal() == 0x00 || request->intVal() == 0x01) // idle
    {
        ui->stbMain->showMessage("Restarting firmware...", 1000);
        Register *reloadProgramRegister = m_registers->get(RELOAD_PROGRAM_REGISTER_NAME);
        reloadProgramRegister->write(0);
    }
    else
    {
        ui->stbMain->clearMessage();
        QMessageBox::warning(this, "Firmware Restart", "The firmware will not be restarted as the system is not currently idle. Try again later.");
    }
}

void MainWindow::onSystemOperatingStateError(RegisterRequest *, request_error_t)
{
    ui->stbMain->clearMessage();
    QMessageBox::warning(this, "Firmware Restart", "The firmware will not be restarted as a communication failure occurred. Try again later.");
}

void MainWindow::on_actionUpdateDSP_triggered()
{
    QString filepath = QFileDialog::getOpenFileName(this, "Choose firmware file...", QString(), "Firmware (*.bin)");
    if (filepath.isEmpty()) return;

    QFile file(filepath);
    file.open(QIODevice::ReadOnly);
    QByteArray data = file.readAll();
    if ((unsigned) data.length() > FLASH_SECTOR_WORDS * sizeof(int32_t) || (unsigned) data.length() > COPY_BUFFER_WORDS * sizeof(int32_t))
    {
        QMessageBox::warning(this, "Firmware Upload", "The firmware binary is too big. The firmware will not be uploaded.");
        return;
    }

#ifdef ENABLE_MULTI_ACCESS_RAM_WORKAROUND
    // stop logger
    m_registers->get(COMMAND_REGISTER_NAME)->write(COMMAND_STOP_LOG);
#endif

    Block *block = m_blocks->get(DSP_FIRMWARE_BLOCK_NAME);
    block->write(data);
    lblStatus->setText("Flashing firmware...");
}

void MainWindow::onDSPFlashDone(Block *)
{
#ifdef ENABLE_MULTI_ACCESS_RAM_WORKAROUND
    // stop logger
    m_registers->get(COMMAND_REGISTER_NAME)->write(COMMAND_START_LOG);
#endif

    QMessageBox::information(this, "Firmware Upload", "The firmware has been updated successfully.");
    lblStatus->clear();
}

void MainWindow::onDSPFlashError(Block *, request_error_t errCode)
{
#ifdef ENABLE_MULTI_ACCESS_RAM_WORKAROUND
    // stop logger
    m_registers->get(COMMAND_REGISTER_NAME)->write(COMMAND_START_LOG);
#endif

    QMessageBox::warning(this, "Firmware Upload", "An error occurred while attempting to flash the firmware.\nError: " + SomeRequest::getErrorDesc(errCode) + " (code: " + QString::number(errCode) + ")");
    lblStatus->clear();
}

void MainWindow::on_comboMode_currentIndexChanged(const QString &arg1)
{
    if (arg1.compare("DC") == 0)
		m_registers->get("MODE")->write(MODE_DC);
    else if (arg1.compare("Waveform") == 0)
		m_registers->get("MODE")->write(MODE_WAVEFORM);
}

//Sofian
void MainWindow::onIDChanged()
{
    uint32_t DPC_CC_ID = m_DPC_CC_IDRegister->intVal();
    foreach (QWidget *widget, QApplication::allWidgets())
    {
        QString tempWindowTitle = "";

        if (widget->objectName() == "MainWindow")
            tempWindowTitle = QString("%1 v%2.%3")
                    .arg("Main Control")
                    .arg(VERSION)
                    .arg(BUILD_NUMBER);
        else if (widget->objectName() == "FaultsWindow")
            tempWindowTitle = "SCE Faults";
        else if (widget->objectName() == "PlotterWindow")
            tempWindowTitle = "Plotter";
        else if (widget->objectName() == "LoggerWindow")
            tempWindowTitle = "Logger";
        else if (widget->objectName() == "RegistersWindow")
            tempWindowTitle = "Raw Registers Control";
        else if (widget->objectName() == "WaveformsWindow")
            tempWindowTitle = "Waveforms";
        else if  (widget->objectName() == "DPC_FAULTS_WINDOW")
            tempWindowTitle = "DPC Faults";

        if (widget->objectName() == "AboutWindow")
            widget->setWindowTitle("About");
        else widget->setWindowTitle(QString("%1 - DPC_CC_ID: %2 - %3")
                                    .arg(tempWindowTitle)
                                    .arg(DPC_CC_ID)
                                    .arg(m_devices->get(DPC_CC_ID)));
    }
}

//Sofian
//Sofian
void MainWindow::onILOADChanged()
{
    if (m_ILOADRegister->valid())
        ui->lblILOAD->setText(QString::number(m_ILOADRegister->floatVal(), 'f', 3) + " A");
    else
        ui->lblILOAD->setText("N/A");
}
