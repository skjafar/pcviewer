#ifndef REQUEST_H
#define REQUEST_H

#include <QObject>

enum request_error_t
{
    REQUEST_ERROR_UNKNOWN,
    REQUEST_ERROR_ADDRESS_MISMATCH,
    REQUEST_ERROR_SIZE_MISMATCH,
    REQUEST_ERROR_MISMATCH,
    REQUEST_ERROR_WRITE_FAILED,
    REQUEST_ERROR_TIMEOUT,
    REQUEST_ERROR_MAX,
};

const uint16_t STATUS_RAW = 0x0000;

const QString errorDesc[6] = {
    "unknown error occurred",
    "address mismatch",
    "size mismatch",
    "request type mismatch",
    "write failed",
    "timed-out",
};

#include "model/register_request.h"
#include "model/block_request.h"

class RegisterRequest;
class BlockRequest;

enum SomeRequestType
{
    SomeRequestType_None,
    SomeRequestType_Register,
    SomeRequestType_Block
};

struct SomeRequest
{
public:
    SomeRequest(RegisterRequest *request, int timeout = 1000);
    SomeRequest(BlockRequest *blockRequest, int timeout = 10000);
    SomeRequest();

    RegisterRequest* getRegisterRequest();
    BlockRequest* getBlockRequest();
    SomeRequestType type() const { return m_requestType; }
    int timeout() const { return m_timeout; }

    static QString getErrorDesc(request_error_t errorCode);

private:
    union
    {
        RegisterRequest* request;
        BlockRequest* blockRequest;
    };

    SomeRequestType m_requestType;
    int m_timeout;
};

#endif // REQUEST_H
