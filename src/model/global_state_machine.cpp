#include "model/global_state_machine.h"
#include "data/data.h"

GlobalStateMachine::GlobalStateMachine(Register* stateMachineRegister, Register* sequencerRegister, Register* commandRegister, QObject *parent) :
    QObject(parent), m_stateMachineRegister(stateMachineRegister), m_sequencerRegister(sequencerRegister), m_commandRegister(commandRegister), m_stateMachinePoller(NULL), m_sequencerPoller(NULL), m_state(GLOBAL_STATE_INVALID), m_sequencerState(SEQ_STATE_IDLE)
{
    connect(stateMachineRegister, SIGNAL(onChange()), this, SLOT(onStateMachineRegisterChange()));
    connect(sequencerRegister, SIGNAL(onChange()), this, SLOT(onSequencerStateRegisterChange()));

    connect(stateMachineRegister, SIGNAL(onError(request_error_t)), this, SLOT(onError(request_error_t)));
    connect(sequencerRegister, SIGNAL(onError(request_error_t)), this, SLOT(onError(request_error_t)));
    connect(commandRegister, SIGNAL(onError(request_error_t)), this, SLOT(onError(request_error_t)));

    m_stateMachinePoller = stateMachineRegister->getPoller(this);
    m_sequencerPoller = sequencerRegister->getPoller(this);

    this->monitor();
}

void GlobalStateMachine::onError(request_error_t)
{
    this->m_state = GLOBAL_STATE_INVALID;
    emit onError();
}

void GlobalStateMachine::monitor(bool enable)
{
    this->m_stateMachinePoller->enablePoll(enable);
    this->m_sequencerPoller->enablePoll(enable);
}

void GlobalStateMachine::onStateMachineRegisterChange()
{
    global_state_t state = (global_state_t) m_stateMachineRegister->uintVal();
    this->m_state = state;
    emit afterStateChange();
}

void GlobalStateMachine::onSequencerStateRegisterChange()
{
    sequencer_state_t state = (sequencer_state_t) m_sequencerRegister->uintVal();
    this->m_sequencerState = state;
    emit afterStateChange();
}

global_state_t GlobalStateMachine::currentState()
{
    return this->m_state;
}

sequencer_state_t GlobalStateMachine::currentSequencerState()
{
    return this->m_sequencerState;
}

void GlobalStateMachine::setState(global_state_t state)
{
    switch (state)
    {
    case GLOBAL_STATE_OFF:
        this->sendCommand(COMMAND_OFF);
        break;
    case GLOBAL_STATE_STANDBY:
        this->sendCommand(COMMAND_STANDBY);
        break;
    case GLOBAL_STATE_ON:
        this->sendCommand(COMMAND_ON);
        break;
    case GLOBAL_STATE_OPENLOOP:
        this->sendCommand(COMMAND_OPENLOOP);
        break;
    default:
        Q_ASSERT(0);
    }
}

void GlobalStateMachine::resetInterlocks()
{
    this->sendCommand(COMMAND_RESET);
}

void GlobalStateMachine::sendCommand(command_t command)
{
    m_commandRegister->write((uint32_t) command);
}
