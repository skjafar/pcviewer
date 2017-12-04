#include "model/register_request.h"

RegisterRequest::RegisterRequest(RegisterRequestType requestType, uint16_t address, QObject *parent) :
    QObject(parent), getNextRequest(NULL), m_userArg(NULL), m_requestType(requestType), m_address(address), m_uint(0)
{
}

void RegisterRequest::setData(uint32_t value)
{
    this->m_uint = value;
}

void RegisterRequest::setData(int32_t value)
{
    this->m_int = value;
}

void RegisterRequest::setData(float value)
{
    this->m_float = value;
}

uint32_t RegisterRequest::messageLength() const
{
    const uint32_t STATUS_LENGTH = 2;
    const uint32_t TYPE_LENGTH = 2;
    const uint32_t ADD_LENGTH = 2;
    const uint32_t MSG_LENGTH = 4;
    return STATUS_LENGTH + TYPE_LENGTH + ADD_LENGTH + MSG_LENGTH;
}

uint32_t RegisterRequest::remainingBytes() const
{
    return this->messageLength();
}

char* RegisterRequest::getMessage() const
{
    char* msg = (char*) malloc(messageLength());
    memcpy(msg + 0, &STATUS_RAW, 2);
    memcpy(msg + 2, &m_requestType, 2);
    uint16_t address = m_address | 0x4000;
    memcpy(msg + 4, &address, 2);
    memcpy(msg + 6, &m_uint, 4);
    return msg;
}

void RegisterRequest::onTimeout()
{
    emit onError(this, REQUEST_ERROR_TIMEOUT);
    emit onHandlingDone(this);
}

SomeRequest RegisterRequest::handleResponse(char *response, size_t responseLength)
{
    if (responseLength != remainingBytes())
    {
        emit onError(this, REQUEST_ERROR_SIZE_MISMATCH);
    }
    else
    {
        uint16_t address;
        uint16_t requestType;
        uint32_t data;

        memcpy(&requestType, response + 2, 2);
        memcpy(&address    , response + 4, 2);
        memcpy(&data       , response + 6, 4);

        if ((address && 0xFF) != (m_address && 0xFF))
            emit onError(this, REQUEST_ERROR_ADDRESS_MISMATCH);
        else if (requestType != m_requestType)
            emit onError(this, REQUEST_ERROR_MISMATCH);
        else if (requestType == RegisterRequestType_Write && data != m_uint)
            emit onError(this, REQUEST_ERROR_WRITE_FAILED);
        else
        {
            m_uint = data;

            if (requestType == RegisterRequestType_Read)
                emit onReadDone(this);
            else if (requestType == RegisterRequestType_Write)
                emit onWriteDone(this);

            emit onReply(this);
        }
    }

    SomeRequest request;
    if (getNextRequest != NULL)
        request = getNextRequest(m_userArg);
    else
        request = SomeRequest();

    emit onHandlingDone(this);
    return request;
}

void RegisterRequest::freeMessage(char* message)
{
    free(message);
    message = NULL;
}
