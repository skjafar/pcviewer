#ifndef BLOCK_H
#define BLOCK_H

#include <QObject>
#include <QString>

#include "model/communicator.h"
#include "model/registers_map.h"
#include "model/block_request_machine.h"

class BlockRequestMachine;

class Block : public QObject
{
    Q_OBJECT
public:
    explicit Block(Communicator* communicator, RegistersMap* registers, QString name, uint32_t address, uint32_t offset, uint32_t numberOfRegisters, QObject *parent = 0);
    ~Block();

    bool isRAM() const;
    bool isParameterSet() const;
    uint32_t address() const;
    uint32_t offset() const;
    uint32_t numberOfRegisters() const;
    QString name() const;

signals:
    void onReadDone(Block*, QByteArray);
    void onWriteDone(Block*);
    void onError(Block*, request_error_t errorCode);

public slots:
    void read();
    void write(QByteArray);

private slots:
    void onMachineReadDone(BlockRequestMachine *);
    void onMachineWriteDone(BlockRequestMachine *);
    void onMachineError(BlockRequestMachine *, request_error_t errorCode);

private:
    Communicator* m_communicator;
    RegistersMap* m_registers;
    QString m_name;
    uint32_t m_address;
    uint32_t m_offset;
    uint32_t m_numberOfRegisters;
};

#endif // BLOCK_H
