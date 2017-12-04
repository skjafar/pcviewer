#include "model/request.h"

SomeRequest::SomeRequest(RegisterRequest *request, int timeout)
{
    this->m_requestType = SomeRequestType_Register;
    this->m_timeout = timeout;
    this->request = request;
}

SomeRequest::SomeRequest(BlockRequest *blockRequest, int timeout)
{
    this->m_requestType = SomeRequestType_Block;
    this->m_timeout = timeout;
    this->blockRequest = blockRequest;
}

SomeRequest::SomeRequest()
{
    this->m_requestType = SomeRequestType_None;
}

RegisterRequest* SomeRequest::getRegisterRequest()
{
    Q_ASSERT(this->m_requestType == SomeRequestType_Register);
    return this->request;
}

BlockRequest* SomeRequest::getBlockRequest()
{
    Q_ASSERT(this->m_requestType == SomeRequestType_Block);
    return this->blockRequest;
}

QString SomeRequest::getErrorDesc(request_error_t errorCode)
{
    if (errorCode >= 0 && errorCode < REQUEST_ERROR_MAX)
        return errorDesc[errorCode];
    else
        return QString("unknown error");
}
