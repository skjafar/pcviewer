#ifndef BLOCKSMAP_H
#define BLOCKSMAP_H

#include <QString>
#include <QMap>

#include "model/communicator.h"
#include "model/block.h"

struct BlocksMap
{
public:
    explicit BlocksMap(Communicator* communicator, RegistersMap* registers);
    ~BlocksMap();

    bool loadFromFile(QString filepath);
    Block* get(QString name);

    // TODO: remove from public interface and provide an iterator
    QMap<QString, Block*> blocksByName;

private:
    Communicator* m_communicator;
    RegistersMap* m_registers;
};

#endif // BLOCKSMAP_H
