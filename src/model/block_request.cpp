#include "model/block_request.h"

BlockRequest::BlockRequest(BlockRequestType requestType, uint32_t address, uint32_t offset, uint32_t numberOfRegisters, QObject *parent) :
    QObject(parent), m_requestType(requestType), m_address(address), m_offset(offset), m_numberOfRegisters(numberOfRegisters)
{
}

void BlockRequest::setData(QByteArray data)
{
    //Q_ASSERT(((uint32_t) data.length() / sizeof(float)) == m_numberOfRegisters);
    m_data = data;
}

void BlockRequest::appendBytes(const char* bytes, size_t len)
{
    this->m_data.append(bytes, len);
}

char* BlockRequest::getMessage() const
{
    char* msg = (char*) malloc(messageLength());
    if (m_requestType == BlockRequestType_Read)
    {
        msg[0] = BlockRequestType_Read;
        memcpy(msg + 1, &m_offset, 4);
        memcpy(msg + 5, &m_numberOfRegisters, 4);
        return msg;
    }
    else if (m_requestType == BlockRequestType_Write)
    {
        uint32_t length = m_data.length() / sizeof(float);
        msg[0] = BlockRequestType_Write;
        memcpy(msg + 1, &m_offset, 4);
        memcpy(msg + 5, &length, 4);
        memcpy(msg + 9, m_data.data(), m_data.length());
        return msg;
    }
    else
    {
        Q_ASSERT(0);
    }
}

void BlockRequest::freeMessage(char* message) const
{
    free(message);
}

uint32_t BlockRequest::messageLength() const
{
    const uint32_t CMD_LENGTH = 1;
    const uint32_t ADDRESS_LENGTH = 4;
    const uint32_t LENGTH_LENGTH = 4;
    const uint32_t BASE_LENGTH = CMD_LENGTH + ADDRESS_LENGTH + LENGTH_LENGTH;

    if (m_requestType == BlockRequestType_Read)
        return BASE_LENGTH;
    else if (m_requestType == BlockRequestType_Write)
        return BASE_LENGTH + this->m_data.length();
    else
        Q_ASSERT(0);
}

void BlockRequest::onTimeout()
{
    emit onError(this, REQUEST_ERROR_TIMEOUT);
}

uint32_t BlockRequest::remainingBytes() const
{
    if (m_requestType == BlockRequestType_Read)
        return m_numberOfRegisters * sizeof(uint32_t) - m_data.length();
    else if (m_requestType == BlockRequestType_Write)
        return 0;
    else
        Q_ASSERT(0);
}

SomeRequest BlockRequest::handleResponse()
{
    Q_ASSERT(remainingBytes() == 0);
    // TODO: consider timeout

    if (m_requestType == BlockRequestType_Read)
        emit onReadDone(this);
    else if (m_requestType == BlockRequestType_Write)
        emit onWriteDone(this);

    SomeRequest request;
    if (getNextRequest != NULL)
        request = getNextRequest(m_userArg);
    else
        request = SomeRequest();

    emit onHandlingDone(this);
    return request;
}
