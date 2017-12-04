#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <QLabel>

#include "model/global_state_machine.h"
#include "model/registers_map.h"
#include "model/blocks_map.h"
#include "model/faults_map.h"
#include "model/parameter_set.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(RegistersMap *registers, BlocksMap *blocks, FaultsMap *faultsMap, ParameterDefinitions *parameterSetDefinitons, QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionParameterizationDownload_triggered();
    void on_actionParameterizationUpload_triggered();
    void on_actionRawRegistersShow_triggered();
    void on_actionWaveformSettings_triggered();
    void on_actionPlotterShow_triggered();
    void on_actionLoggerShow_triggered();
    void on_actionDPCFaultsShow_triggered();
    void on_actionFaultsShow_triggered();
    void on_actionRestartFirmware_triggered();
    void on_actionTest_triggered();
    void on_actionStates_triggered();
    void on_actionTune_triggered();

    void on_btnOff_clicked();
    void on_btnStandby_clicked();
    void on_btnON_clicked();
    void on_btnReset_clicked();
    void on_btnPause_clicked();
    void on_btnTrigger_clicked();
    void on_btnResume_clicked();
    void on_btnStop_clicked();
    void on_btnSemiAutomatic_clicked();
    void on_btnAutomatic_clicked();
    void on_btnManual_clicked();
    void on_btnSendInterlock_clicked();
    void on_btnWaveformSettings_clicked();
    void on_btnSkip_clicked();
    void on_actionUpdateDSP_triggered();

    void on_txtReferenceCurrent_returnPressed();

    void onReferenceCurrentChanged();

    void onStateChanged();
    void onNextWaveformChanged();

    void onIDChanged(); //sofian
    void onILOADChanged(); //Sofian

    void enableWrite(bool enable);
    void onWriteEnableChanged();

    void onParameterSetReadDone(Block *block, QByteArray data);
    void onParameterSetWriteDone(Block *block);
    void onParameterSetCommError(Block *block, request_error_t errCode);

    void onDSPFlashDone(Block *block);
    void onDSPFlashError(Block *block, request_error_t errCode);

    void onSystemOperatingStateRead(RegisterRequest*);
    void onSystemOperatingStateError(RegisterRequest*, request_error_t);

    void on_comboMode_currentIndexChanged(const QString &arg1);

    void on_btnOpenloop_clicked();

private:
    Ui::MainWindow *ui;

    RegistersMap *m_registers;
    BlocksMap *m_blocks;
    FaultsMap *m_faults;
    ParameterDefinitions *m_parameterSetDefinitions;

    GlobalStateMachine *m_globalStateMachine;

	Register *m_stateRegister;
    Register *m_ILOADRegister;      //Sofian
    Register *m_DPC_CC_IDRegister; //Sofian
    Register *m_referenceCurrentRegister;
    Register *m_priorityRegister;
    Register *m_nextWaveformRegister;

    QLabel *lblPriority;
    QLabel *lblStatus;
};

#endif // MAIN_WINDOW_H
