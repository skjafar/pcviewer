#ifndef GLOBAL_STATE_MACHINE_H
#define GLOBAL_STATE_MACHINE_H

#include <QObject>
#include "model/register.h"
#include "data/data.h"

class GlobalStateMachine : public QObject
{
    Q_OBJECT
public:
    explicit GlobalStateMachine(Register* stateMachineRegister, Register* sequencerRegister, Register* commandRegister, QObject *parent = 0);
    void monitor(bool enable = true);
    global_state_t currentState();
    sequencer_state_t currentSequencerState();
    void sendCommand(command_t command);

signals:
    void afterStateChange();
    void onError();

public slots:
    void setState(global_state_t state);
    void resetInterlocks();

private slots:
    void onStateMachineRegisterChange();
    void onSequencerStateRegisterChange();
    void onError(request_error_t errorCode);

private:
    Register* m_stateMachineRegister;
    Register* m_sequencerRegister;
    Register* m_commandRegister;
    RegisterPoll* m_stateMachinePoller;
    RegisterPoll* m_sequencerPoller;

    global_state_t m_state;
    sequencer_state_t m_sequencerState;
};

#endif // GLOBAL_STATE_MACHINE_H
