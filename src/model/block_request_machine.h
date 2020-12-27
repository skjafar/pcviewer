#ifndef BLOCK_REQUEST_MACHINE_H
#define BLOCK_REQUEST_MACHINE_H

#include <QObject>
#include <QElapsedTimer>

#include "model/block.h"
#include "model/request.h"
#include "model/registers_map.h"

class Block;

enum BlockRequestReadState : uint8_t
{
    BlockRequestReadState_Initial,
    BlockRequestReadState_VerifySectorSet,
    BlockRequestReadState_SectorSet,
    BlockRequestReadState_Transient,
    BlockRequestReadState_ReadReady,
    BlockRequestReadState_Read,
    BlockRequestReadState_AfterRead,
    BlockRequestReadState_Error
};

enum BlockRequestWriteState : uint8_t
{
    BlockRequestWriteState_Initial,
    BlockRequestWriteState_SetupSet,
    BlockRequestWriteState_DownloadReady,
    BlockRequestWriteState_DownloadDone,
    BlockRequestWriteState_Idle,
    BlockRequestWriteState_WriteToFlash,
    BlockRequestWriteState_Saving,
    BlockRequestWriteState_Written,
    BlockRequestWriteState_AfterWrite,
    BlockRequestWriteState_Error
};

class BlockRequestMachine : public QObject
{
    Q_OBJECT
public:
    explicit BlockRequestMachine(BlockRequestType type, Block* block, RegistersMap *registers, QObject *parent = 0);
    SomeRequest getRequest();
    QByteArray data() const { return this->m_data; }
    void setData(QByteArray data) { this->m_data = data; }

private:
    SomeRequest readAction();
    void readTransition(SomeRequest);
    SomeRequest writeAction();
    void writeTransition(SomeRequest);

signals:
    void onReadDone(BlockRequestMachine *);
    void onWriteDone(BlockRequestMachine *);
    void onError(BlockRequestMachine *, request_error_t errorCode);

private slots:
    void registerRequestDone(RegisterRequest *request);
    void registerRequestDelete(RegisterRequest *request);
    void registerRequestError(RegisterRequest *request, request_error_t errCode);

    void blockRequestDone(BlockRequest *request);
    void blockRequestDelete(BlockRequest *request);
    void blockRequestError(BlockRequest *request, request_error_t errCode);

private:
    Block *m_block;
    BlockRequestType m_requestType;
    QByteArray m_data;

    union
    {
        BlockRequestReadState  m_readState;
        BlockRequestWriteState m_writeState;
    };

    Register* m_dataTransferInitRegister;
    Register* m_dataBlockDestinationRegister;
    Register* m_deviceOperatingStateRegister;
    Register* m_systemOperatingStateRegister;

    QElapsedTimer m_timer;
};

#endif // BLOCK_REQUEST_MACHINE_H
