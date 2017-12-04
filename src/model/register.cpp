#include "model/register.h"
#include "model/communicator.h"

#include <QString>

Register::Register(Communicator* communicator, uint16_t address, QString name, RegisterType type, bool showAsHex, QObject *parent) :
    QObject(parent), showAsHex(showAsHex), m_address(address), m_name(name), m_type(type), m_valid(false), m_uint(0), m_communicator(communicator)
{
}

RegisterPoll* Register::getPoller(int pollInterval_ms, QObject *parent)
{
    return new RegisterPoll(this, pollInterval_ms, parent == NULL ? this : parent);
}

RegisterPoll* Register::getPoller(QObject *parent)
{
    return new RegisterPoll(this, DEFAULT_POLL_INTERVAL, parent == NULL ? this : parent);
}

void Register::read()
{
    RegisterRequest* request = new RegisterRequest(RegisterRequestType_Read, m_address, this);
    connect(request, SIGNAL(onReply(RegisterRequest*)), this, SLOT(onReadReply(RegisterRequest*)));
    connect(request, SIGNAL(onError(RegisterRequest*, request_error_t)), this, SLOT(onReadError(RegisterRequest*, request_error_t)));
    connect(request, SIGNAL(onHandlingDone(RegisterRequest*)), this, SLOT(onHandlingDone(RegisterRequest*)));

    m_communicator->queueRequest(request);
}

void Register::onReadReply(RegisterRequest* request)
{
    bool old_valid = this->m_valid;
    uint32_t old_value = this->m_uint;

    this->m_uint = request->uintVal();
    this->m_valid = true;

    emit onReadReply();
    if (!old_valid || (old_value != this->m_uint)) emit onChange();
}

void Register::onHandlingDone(RegisterRequest* request)
{
    request->deleteLater();
}

void Register::onReadError(RegisterRequest*, request_error_t errorCode)
{
    bool old_valid = this->m_valid;
    this->m_valid = false;

    emit onReadReply();
    emit onReadError(errorCode);
    emit onError(errorCode);

    if (old_valid) emit onChange();
}

void Register::onWriteError(RegisterRequest*, request_error_t errorCode)
{
    emit onWriteError(errorCode);
    emit onError(errorCode);
}

// Write register methods

void Register::write(int32_t value)
{
    RegisterRequest* request = new RegisterRequest(RegisterRequestType_Write, m_address, this);
    request->setData(value);
    connect(request, SIGNAL(onError(RegisterRequest*, request_error_t)), this, SLOT(onWriteError(RegisterRequest*, request_error_t)));
    m_communicator->queueRequest(request);
}

void Register::write(uint32_t value)
{
    RegisterRequest* request = new RegisterRequest(RegisterRequestType_Write, m_address, this);
    request->setData(value);
    connect(request, SIGNAL(onError(RegisterRequest*, request_error_t)), this, SLOT(onWriteError(RegisterRequest*, request_error_t)));
    m_communicator->queueRequest(request);
}

void Register::write(float value)
{
    RegisterRequest* request = new RegisterRequest(RegisterRequestType_Write, m_address, this);
    request->setData(value);
    connect(request, SIGNAL(onError(RegisterRequest*, request_error_t)), this, SLOT(onWriteError(RegisterRequest*, request_error_t)));
    m_communicator->queueRequest(request);
}

QString Register::toString() const
{
    if (m_valid)
    {
        if (m_type == REGISTER_TYPE_INTEGRAL)
            return (showAsHex ? "0x" : "") + QString::number(m_int, showAsHex ? 16 : 10);
        else
            return QString("%1").arg(m_float, 4, 'f', 4);
    }
    else
        return "N/A";
}
