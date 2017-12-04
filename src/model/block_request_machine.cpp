#include "model/block_request_machine.h"
#include "data/data.h"

BlockRequestMachine::BlockRequestMachine(BlockRequestType type, Block *block, RegistersMap *registers, QObject *parent) :
    QObject(parent), m_block(block), m_requestType(type), m_data()
{
    if (m_requestType == BlockRequestType_Read)
       m_readState = BlockRequestReadState_Initial;
    else if (m_requestType == BlockRequestType_Write)
       m_writeState = BlockRequestWriteState_Initial;

    this->m_dataTransferInitRegister     = registers->get(DATA_TRANSFER_INIT_REGISTER_NAME);
    this->m_dataBlockDestinationRegister = registers->get(DATA_BLOCK_DESTINATION_REGISTER_NAME);
    this->m_deviceOperatingStateRegister = registers->get(DEVICE_OPERATING_STATE_REGISTER_NAME);
    this->m_systemOperatingStateRegister = registers->get(SYSTEM_OPERATING_STATE_REGISTER_NAME);
}

SomeRequest nextTransitionRequest(void* userArg)
{
    BlockRequestMachine* blockRequest = (BlockRequestMachine*) userArg;
    return blockRequest->getRequest();
}

void BlockRequestMachine::registerRequestDone(RegisterRequest *request)
{
    if (m_requestType == BlockRequestType_Read)
        this->readTransition(SomeRequest(request));
    else if (m_requestType == BlockRequestType_Write)
        this->writeTransition(SomeRequest(request));
    else
        Q_ASSERT(0);

    request->m_userArg = this;
    request->getNextRequest = nextTransitionRequest;
}

void BlockRequestMachine::blockRequestDone(BlockRequest *request)
{
    if (m_requestType == BlockRequestType_Read)
        this->readTransition(SomeRequest(request));
    else if (m_requestType == BlockRequestType_Write)
        this->writeTransition(SomeRequest(request));
    else
        Q_ASSERT(0);

    request->m_userArg = this;
    request->getNextRequest = nextTransitionRequest;
}

void BlockRequestMachine::registerRequestDelete(RegisterRequest *request)
{
    request->deleteLater();
}

void BlockRequestMachine::blockRequestDelete(BlockRequest *request)
{
    request->deleteLater();
}

void BlockRequestMachine::registerRequestError(RegisterRequest *, request_error_t errCode)
{
    emit onError(this, errCode);
}

void BlockRequestMachine::blockRequestError(BlockRequest *, request_error_t errCode)
{
    emit onError(this, errCode);
}

SomeRequest BlockRequestMachine::getRequest()
{
    if (m_requestType == BlockRequestType_Read)
        return this->readAction();
    else if (m_requestType == BlockRequestType_Write)
        return this->writeAction();
    else
        Q_ASSERT(0);
}

void BlockRequestMachine::readTransition(SomeRequest request)
{
    Q_ASSERT(m_requestType == BlockRequestType_Read);

    switch (m_readState)
    {

    case BlockRequestReadState_Initial:
    {
        m_readState = BlockRequestReadState_VerifySectorSet;
        m_timer.start();
    }
    break;

    case BlockRequestReadState_VerifySectorSet:
    {
        RegisterRequest *registerRequest = request.getRegisterRequest();

        if (registerRequest->uintVal() == m_block->address())
        {
            m_readState = BlockRequestReadState_SectorSet;
            m_timer.restart();
        }
    }
    break;

    case BlockRequestReadState_SectorSet:
    {
        RegisterRequest *registerRequest = request.getRegisterRequest();

        if (m_block->isParameterSet() && registerRequest->uintVal() == DEVICE_STATE_MODIFY_DATA)
        {
            m_readState = BlockRequestReadState_ReadReady;
            m_timer.restart();
        }
        else if (!m_block->isParameterSet() && registerRequest->uintVal() == DEVICE_STATE_TRANSIENT)
        {
            m_readState = BlockRequestReadState_Transient;
            m_timer.restart();
        }
    }
    break;

    case BlockRequestReadState_Transient:
    {
        RegisterRequest *registerRequest = request.getRegisterRequest();
        if (registerRequest->uintVal() == 0x00 || registerRequest->uintVal() == 0x01)
        {
            m_readState = BlockRequestReadState_ReadReady;
            m_timer.restart();
        }
    }
    break;

    case BlockRequestReadState_ReadReady:
    {
        BlockRequest *blockRequest = request.getBlockRequest();
        m_data = QByteArray(blockRequest->data());
        m_readState = BlockRequestReadState_Read;
    }
    break;

    case BlockRequestReadState_Read:
    {
        m_readState = BlockRequestReadState_AfterRead;
    }
    break;

    default:
    {
        Q_ASSERT(0); // entered unknown state
    }

    }
}

SomeRequest BlockRequestMachine::readAction()
{
    Q_ASSERT(m_requestType == BlockRequestType_Read);

    switch (m_readState)
    {

    case BlockRequestReadState_Initial:
    {
        // check system operating state, it should not be 0x0, 0x1 (unimplemented)
        // check device operating state, it should not be "ON" (as defined in app defs (unimplemented))

        // write to data transfer init register the sector
        RegisterRequest *registerRequest = new RegisterRequest(RegisterRequestType_Write, m_dataTransferInitRegister->address(), this);
        registerRequest->setData(m_block->address());
        connect(registerRequest, SIGNAL(onHandlingDone(RegisterRequest*)), this, SLOT(registerRequestDelete(RegisterRequest*)));
        connect(registerRequest, SIGNAL(onWriteDone(RegisterRequest*)), this, SLOT(registerRequestDone(RegisterRequest*)), Qt::DirectConnection);
        connect(registerRequest, SIGNAL(onError(RegisterRequest*,request_error_t)), this, SLOT(registerRequestError(RegisterRequest*,request_error_t)));
        return SomeRequest(registerRequest);
    }

    case BlockRequestReadState_VerifySectorSet:
    {
        // wait with a timeout of 500ms to verify sector set
        if (m_timer.elapsed() < 500)
        {
            RegisterRequest *registerRequest = new RegisterRequest(RegisterRequestType_Read, m_dataTransferInitRegister->address(), this);
            connect(registerRequest, SIGNAL(onHandlingDone(RegisterRequest*)), this, SLOT(registerRequestDelete(RegisterRequest*)));
            connect(registerRequest, SIGNAL(onReadDone(RegisterRequest*)), this, SLOT(registerRequestDone(RegisterRequest*)), Qt::DirectConnection);
            connect(registerRequest, SIGNAL(onError(RegisterRequest*,request_error_t)), this, SLOT(registerRequestError(RegisterRequest*,request_error_t)));
            return SomeRequest(registerRequest);
        }
        else
        {
            emit onError(this, REQUEST_ERROR_TIMEOUT);
            return SomeRequest();
        }
    }

    case BlockRequestReadState_SectorSet:
    {
        // wait with a timeout of 500ms for transient state
        if (m_timer.elapsed() < 500)
        {
            RegisterRequest *registerRequest = new RegisterRequest(RegisterRequestType_Read, m_systemOperatingStateRegister->address(), this);
            connect(registerRequest, SIGNAL(onHandlingDone(RegisterRequest*)), this, SLOT(registerRequestDelete(RegisterRequest*)));
            connect(registerRequest, SIGNAL(onReadDone(RegisterRequest*)), this, SLOT(registerRequestDone(RegisterRequest*)), Qt::DirectConnection);
            connect(registerRequest, SIGNAL(onError(RegisterRequest*,request_error_t)), this, SLOT(registerRequestError(RegisterRequest*,request_error_t)));
            return SomeRequest(registerRequest);
        }
        else
        {
            emit onError(this, REQUEST_ERROR_TIMEOUT);
            return SomeRequest();
        }
    }

    case BlockRequestReadState_Transient:
    {
        // wait with a timeout of 10000 for idle
        if (m_timer.elapsed() < 10000)
        {
            RegisterRequest *registerRequest = new RegisterRequest(RegisterRequestType_Read, m_systemOperatingStateRegister->address(), this);
            connect(registerRequest, SIGNAL(onHandlingDone(RegisterRequest*)), this, SLOT(registerRequestDelete(RegisterRequest*)));
            connect(registerRequest, SIGNAL(onReadDone(RegisterRequest*)), this, SLOT(registerRequestDone(RegisterRequest*)), Qt::DirectConnection);
            connect(registerRequest, SIGNAL(onError(RegisterRequest*,request_error_t)), this, SLOT(registerRequestError(RegisterRequest*,request_error_t)));
            return SomeRequest(registerRequest);
        }
        else
        {
            emit onError(this, REQUEST_ERROR_TIMEOUT);
            return SomeRequest();
        }
    }

    case BlockRequestReadState_ReadReady:
    {
        // send the block read request
        BlockRequest *blockRequest = new BlockRequest(m_requestType, m_block->address(), m_block->offset(), m_block->numberOfRegisters(), this);
        connect(blockRequest, SIGNAL(onHandlingDone(BlockRequest*)), this, SLOT(blockRequestDelete(BlockRequest*)));
        connect(blockRequest, SIGNAL(onReadDone(BlockRequest*)), this, SLOT(blockRequestDone(BlockRequest*)), Qt::DirectConnection);
        connect(blockRequest, SIGNAL(onError(BlockRequest*,request_error_t)), this, SLOT(blockRequestError(BlockRequest*,request_error_t)), Qt::DirectConnection);
        return SomeRequest(blockRequest);
    }

    case BlockRequestReadState_Read:
    {
        // data is ready, just reset mode
        RegisterRequest *registerRequest = new RegisterRequest(RegisterRequestType_Write, m_dataTransferInitRegister->address(), this);
        registerRequest->setData(0);
        connect(registerRequest, SIGNAL(onHandlingDone(RegisterRequest*)), this, SLOT(registerRequestDelete(RegisterRequest*)));
        connect(registerRequest, SIGNAL(onWriteDone(RegisterRequest*)), this, SLOT(registerRequestDone(RegisterRequest*)), Qt::DirectConnection);
        connect(registerRequest, SIGNAL(onError(RegisterRequest*,request_error_t)), this, SLOT(registerRequestError(RegisterRequest*,request_error_t)));
        return SomeRequest(registerRequest);
    }

    case BlockRequestReadState_AfterRead:
    {
        emit onReadDone(this);
        return SomeRequest();
    }

    case BlockRequestReadState_Error:
    {
        // TODO: add error handling
        emit onError(this, REQUEST_ERROR_UNKNOWN);
        return SomeRequest();
    }

    default:
        Q_ASSERT(0);
    }

    return SomeRequest();
}

void BlockRequestMachine::writeTransition(SomeRequest request)
{
    Q_ASSERT(m_requestType == BlockRequestType_Write);

    switch (m_writeState)
    {

    case BlockRequestWriteState_Initial:
    {
        m_writeState = BlockRequestWriteState_SetupSet;
        m_timer.start();
    }
    break;

    case BlockRequestWriteState_SetupSet:
    {
        RegisterRequest *registerRequest = request.getRegisterRequest();
        if (registerRequest->uintVal() == DEVICE_STATE_DOWNLOAD_DATA)
        {
            m_writeState = BlockRequestWriteState_DownloadReady;
            m_timer.restart();
        }
    }
    break;

    case BlockRequestWriteState_DownloadReady:
    {
        m_writeState = BlockRequestWriteState_DownloadDone;
    }
    break;

    case BlockRequestWriteState_DownloadDone:
    {
        RegisterRequest *registerRequest = request.getRegisterRequest();
        if (registerRequest->uintVal() == 0x00 || registerRequest->uintVal() == 0x01)
        {
            if (m_block->isRAM())
            {
                m_writeState = BlockRequestWriteState_Written;
            }
            else
            {
                m_writeState = BlockRequestWriteState_Idle;
            }
            m_timer.restart();
        }
    }
    break;

    case BlockRequestWriteState_Idle:
    {
        m_writeState = BlockRequestWriteState_WriteToFlash;
        m_timer.restart();
    }
    break;

    case BlockRequestWriteState_WriteToFlash:
    {
        RegisterRequest *registerRequest = request.getRegisterRequest();
        if (registerRequest->uintVal() == DEVICE_STATE_SAVE_DATA)
        {
            m_writeState = BlockRequestWriteState_Saving;
            m_timer.restart();
        }
    }
    break;

    case BlockRequestWriteState_Saving:
    {
        RegisterRequest *registerRequest = request.getRegisterRequest();
        if (registerRequest->uintVal() == 0x00 || registerRequest->uintVal() == 0x01)
        {
            m_writeState = BlockRequestWriteState_Written;
        }
        m_timer.restart();
    }
    break;

    case BlockRequestWriteState_Written:
    {
        m_writeState = BlockRequestWriteState_AfterWrite;
    }
    break;

    default:
    {
        Q_ASSERT(0); // entered unknown state
    }

    }
}

SomeRequest BlockRequestMachine::writeAction()
{
    Q_ASSERT(m_requestType == BlockRequestType_Write);

    switch (m_writeState)
    {

    case BlockRequestWriteState_Initial:
    {
        // write to data transfer init register the sector and length
        RegisterRequest *registerRequest = new RegisterRequest(RegisterRequestType_Write, m_dataTransferInitRegister->address(), this);
        registerRequest->setData((m_block->address() & 0xFF) | ((m_data.length() / 4) << 8));
        connect(registerRequest, SIGNAL(onHandlingDone(RegisterRequest*)), this, SLOT(registerRequestDelete(RegisterRequest*)));
        connect(registerRequest, SIGNAL(onWriteDone(RegisterRequest*)), this, SLOT(registerRequestDone(RegisterRequest*)), Qt::DirectConnection);
        connect(registerRequest, SIGNAL(onError(RegisterRequest*,request_error_t)), this, SLOT(registerRequestError(RegisterRequest*,request_error_t)));
        return SomeRequest(registerRequest);
    }

    case BlockRequestWriteState_SetupSet:
    {
        // wait with a timeout of 10000ms to check system state in 'download'
        if (m_timer.elapsed() < 10000)
        {
            RegisterRequest *registerRequest = new RegisterRequest(RegisterRequestType_Read, m_systemOperatingStateRegister->address(), this);
            connect(registerRequest, SIGNAL(onHandlingDone(RegisterRequest*)), this, SLOT(registerRequestDelete(RegisterRequest*)));
            connect(registerRequest, SIGNAL(onReadDone(RegisterRequest*)), this, SLOT(registerRequestDone(RegisterRequest*)), Qt::DirectConnection);
            connect(registerRequest, SIGNAL(onError(RegisterRequest*,request_error_t)), this, SLOT(registerRequestError(RegisterRequest*,request_error_t)));
            return SomeRequest(registerRequest);
        }
        else
        {
            emit onError(this, REQUEST_ERROR_TIMEOUT);
            return SomeRequest();
        }
    }

    case BlockRequestWriteState_DownloadReady:
    {
        // send the block write request
        BlockRequest *blockRequest = new BlockRequest(m_requestType, m_block->address(), m_block->offset(), m_block->numberOfRegisters(), this);
        blockRequest->setData(m_data);
        connect(blockRequest, SIGNAL(onHandlingDone(BlockRequest*)), this, SLOT(blockRequestDelete(BlockRequest*)));
        connect(blockRequest, SIGNAL(onWriteDone(BlockRequest*)), this, SLOT(blockRequestDone(BlockRequest*)), Qt::DirectConnection);
        connect(blockRequest, SIGNAL(onError(BlockRequest*,request_error_t)), this, SLOT(blockRequestError(BlockRequest*,request_error_t)), Qt::DirectConnection);
        return SomeRequest(blockRequest);
    }

    case BlockRequestWriteState_DownloadDone:
    {
        // wait with a timeout of 10000 for idle
        if (m_timer.elapsed() < 10000)
        {
            RegisterRequest *registerRequest = new RegisterRequest(RegisterRequestType_Read, m_systemOperatingStateRegister->address(), this);
            connect(registerRequest, SIGNAL(onHandlingDone(RegisterRequest*)), this, SLOT(registerRequestDelete(RegisterRequest*)));
            connect(registerRequest, SIGNAL(onReadDone(RegisterRequest*)), this, SLOT(registerRequestDone(RegisterRequest*)), Qt::DirectConnection);
            connect(registerRequest, SIGNAL(onError(RegisterRequest*,request_error_t)), this, SLOT(registerRequestError(RegisterRequest*,request_error_t)));
            return SomeRequest(registerRequest);
        }
        else
        {
            emit onError(this, REQUEST_ERROR_TIMEOUT);
            return SomeRequest();
        }
    }

    case BlockRequestWriteState_Idle:
    {
        // write to data block destination register the sector and length
        RegisterRequest *registerRequest = new RegisterRequest(RegisterRequestType_Write, m_dataBlockDestinationRegister->address(), this);
        registerRequest->setData((m_block->address() & 0xFF) | ((m_data.length() / 4) << 8));
        connect(registerRequest, SIGNAL(onHandlingDone(RegisterRequest*)), this, SLOT(registerRequestDelete(RegisterRequest*)));
        connect(registerRequest, SIGNAL(onWriteDone(RegisterRequest*)), this, SLOT(registerRequestDone(RegisterRequest*)), Qt::DirectConnection);
        connect(registerRequest, SIGNAL(onError(RegisterRequest*,request_error_t)), this, SLOT(registerRequestError(RegisterRequest*,request_error_t)));
        return SomeRequest(registerRequest);
    }

    case BlockRequestWriteState_WriteToFlash:
    {
        // wait with a timeout of 500ms for save data state
        if (m_timer.elapsed() < 500)
        {
            RegisterRequest *registerRequest = new RegisterRequest(RegisterRequestType_Read, m_systemOperatingStateRegister->address(), this);
            connect(registerRequest, SIGNAL(onHandlingDone(RegisterRequest*)), this, SLOT(registerRequestDelete(RegisterRequest*)));
            connect(registerRequest, SIGNAL(onReadDone(RegisterRequest*)), this, SLOT(registerRequestDone(RegisterRequest*)), Qt::DirectConnection);
            connect(registerRequest, SIGNAL(onError(RegisterRequest*,request_error_t)), this, SLOT(registerRequestError(RegisterRequest*,request_error_t)));
            return SomeRequest(registerRequest);
        }
        else
        {
            emit onError(this, REQUEST_ERROR_TIMEOUT);
            return SomeRequest();
        }
    }

    case BlockRequestWriteState_Saving:
    {
        // wait with a timeout of 10000ms for controller to go back to idle
        if (m_timer.elapsed() < 10000)
        {
            RegisterRequest *registerRequest = new RegisterRequest(RegisterRequestType_Read, m_systemOperatingStateRegister->address(), this);
            connect(registerRequest, SIGNAL(onHandlingDone(RegisterRequest*)), this, SLOT(registerRequestDelete(RegisterRequest*)));
            connect(registerRequest, SIGNAL(onReadDone(RegisterRequest*)), this, SLOT(registerRequestDone(RegisterRequest*)), Qt::DirectConnection);
            connect(registerRequest, SIGNAL(onError(RegisterRequest*,request_error_t)), this, SLOT(registerRequestError(RegisterRequest*,request_error_t)));
            return SomeRequest(registerRequest);
        }
        else
        {
            emit onError(this, REQUEST_ERROR_TIMEOUT);
            return SomeRequest();
        }
    }

    case BlockRequestWriteState_Written:
    {
        // data is ready, just reset mode
        RegisterRequest *registerRequest = new RegisterRequest(RegisterRequestType_Write, m_dataTransferInitRegister->address(), this);
        registerRequest->setData(0);
        connect(registerRequest, SIGNAL(onHandlingDone(RegisterRequest*)), this, SLOT(registerRequestDelete(RegisterRequest*)));
        connect(registerRequest, SIGNAL(onWriteDone(RegisterRequest*)), this, SLOT(registerRequestDone(RegisterRequest*)), Qt::DirectConnection);
        connect(registerRequest, SIGNAL(onError(RegisterRequest*,request_error_t)), this, SLOT(registerRequestError(RegisterRequest*,request_error_t)));
        return SomeRequest(registerRequest);
    }

    case BlockRequestWriteState_AfterWrite:
    {
        emit onWriteDone(this);
        return SomeRequest();
    }

    case BlockRequestWriteState_Error:
    {
        emit onError(this, REQUEST_ERROR_UNKNOWN);
        return SomeRequest();
    }

    default:
        Q_ASSERT(0);
    }

    return SomeRequest();
}
