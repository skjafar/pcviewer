#ifndef BLOCK_REQUEST_H
#define BLOCK_REQUEST_H

#include <QObject>
#include "model/request.h"

struct SomeRequest;

enum BlockRequestType : uint8_t
{
    BlockRequestType_Read = 0x01,
    BlockRequestType_Write = 0x02
};

class BlockRequest : public QObject
{
    Q_OBJECT

public:
    explicit BlockRequest(BlockRequestType requestType, uint32_t address, uint32_t offset, uint32_t numberOfRegisters, QObject *parent = 0);

    QByteArray data() const { return this->m_data; }
    BlockRequestType requestType() const { return this->m_requestType; }
    uint32_t remainingBytes() const;
    char* getMessage() const;
    void freeMessage(char* message) const;
    uint32_t messageLength() const;

    void appendBytes(const char* bytes, size_t len);

    SomeRequest handleResponse();
    SomeRequest (*getNextRequest)(void* userArg);
    void* m_userArg;

signals:
    void onReply(BlockRequest* request);
    void onReadDone(BlockRequest* request);
    void onWriteDone(BlockRequest* request);
    void onError(BlockRequest* request, request_error_t errorCode);
    void onHandlingDone(BlockRequest* request);

public slots:
    void setData(QByteArray data);
    void onTimeout();

private:
    BlockRequestType m_requestType;
    uint32_t m_address;
    uint32_t m_offset;
    uint32_t m_numberOfRegisters;
    uint32_t m_remainingBytes;

    QByteArray m_data;
};

#endif // BLOCK_REQUEST_H
