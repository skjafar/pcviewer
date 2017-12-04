#ifndef REGISTER_REQUEST_H
#define REGISTER_REQUEST_H

#include <QObject>
#include "model/request.h"

struct SomeRequest;

enum RegisterRequestType : uint16_t
{
    RegisterRequestType_Read = 0x0001,
    RegisterRequestType_Write = 0x0002,
    RegisterRequestType_Poll = 0x0004,
};

class RegisterRequest : public QObject
{
    Q_OBJECT

public:
    explicit RegisterRequest(RegisterRequestType requestType, uint16_t address, QObject *parent = 0);

    RegisterRequestType requestType() const { return this->m_requestType; }
    uint16_t address() const { return this->m_address; }

    int32_t intVal() const { return this->m_int; }
    uint32_t uintVal() const { return this->m_uint; }
    float floatVal() const { return this->m_float; }

    uint32_t messageLength() const;
    uint32_t remainingBytes() const;

    char* getMessage() const;
    void freeMessage(char* message);

    SomeRequest handleResponse(char* response, size_t responseLength);
    SomeRequest (*getNextRequest)(void* userArg);
    void* m_userArg;

signals:
    void onReply(RegisterRequest* request);
    void onReadDone(RegisterRequest* request);
    void onWriteDone(RegisterRequest* request);
    void onError(RegisterRequest* request, request_error_t errorCode);
    void onHandlingDone(RegisterRequest* request);

public slots:
    void onTimeout();

    void setData(uint32_t value);
    void setData(int32_t value);
    void setData(float value);

private:
    RegisterRequestType m_requestType;
    uint16_t m_address;

    union // TODO: consider memcpy instead of union to please C++ standards committee
    {
        uint32_t m_uint;
        int32_t m_int;
        float m_float;
        char m_bytes[4];
    };
};

#endif // REGISTER_REQUEST_H
