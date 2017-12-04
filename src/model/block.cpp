#include "model/block.h"

Block::Block(Communicator* communicator, RegistersMap* registers, QString name, uint32_t address, uint32_t offset, uint32_t numberOfRegisters, QObject *parent) :
    QObject(parent), m_communicator(communicator), m_registers(registers), m_name(name), m_address(address), m_offset(offset), m_numberOfRegisters(numberOfRegisters)
{}

Block::~Block() {}

bool Block::isRAM() const
{
    return m_name == "RAM";
}

bool Block::isParameterSet() const
{
    return m_address >= 15 && m_address <= 18;
}

uint32_t Block::offset() const
{
    return m_offset;
}

uint32_t Block::address() const
{
    return m_address;
}

uint32_t Block::numberOfRegisters() const
{
    return m_numberOfRegisters;
}

QString Block::name() const
{
    return m_name;
}

void Block::read()
{
    BlockRequestMachine* machine = new BlockRequestMachine(BlockRequestType_Read, this, m_registers, this);
    connect(machine, SIGNAL(onReadDone(BlockRequestMachine*)), this, SLOT(onMachineReadDone(BlockRequestMachine*)));
    connect(machine, SIGNAL(onError(BlockRequestMachine*,request_error_t)), this, SLOT(onMachineError(BlockRequestMachine*,request_error_t)));
    m_communicator->queueRequest(machine->getRequest());
}

void Block::write(QByteArray data)
{
    BlockRequestMachine* machine = new BlockRequestMachine(BlockRequestType_Write, this, m_registers, this);
    machine->setData(data);

    connect(machine, SIGNAL(onWriteDone(BlockRequestMachine*)), this, SLOT(onMachineWriteDone(BlockRequestMachine*)));
    connect(machine, SIGNAL(onError(BlockRequestMachine*,request_error_t)), this, SLOT(onMachineError(BlockRequestMachine*,request_error_t)));
    m_communicator->queueRequest(machine->getRequest());
}

void Block::onMachineReadDone(BlockRequestMachine* machine)
{
    emit onReadDone(this, machine->data());
    machine->deleteLater();
}

void Block::onMachineError(BlockRequestMachine* machine, request_error_t errorCode)
{
    emit onError(this, errorCode);
    machine->deleteLater();
}

void Block::onMachineWriteDone(BlockRequestMachine* machine)
{
    emit onWriteDone(this);
    machine->deleteLater();
}
