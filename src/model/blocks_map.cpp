#include "model/blocks_map.h"

#include <QStringList>
#include <QFile>
#include <QTextStream>

BlocksMap::BlocksMap(Communicator* communicator, RegistersMap* registers) :
    m_communicator(communicator), m_registers(registers)
{
}

bool BlocksMap::loadFromFile(QString filepath)
{
    QFile file(filepath);
    if (!file.open(QIODevice::ReadOnly))
        return false;

    QTextStream stream(&file);

    while (!stream.atEnd())
    {
        // read comma separated values
        QString line = stream.readLine();

        if (line.isEmpty()) continue;
        if (line.startsWith("//") || line.startsWith("#")) continue;

        QStringList fields = line.split(",");
        if (fields.count() == 4)
        {
            Block* blk = new Block(
                m_communicator,
                m_registers,
                /*name*/ fields.at(0),
                /*sector address*/ fields.at(1).toUInt(),
                /*offset*/ fields.at(2).toUInt(),
                /*size*/ fields.at(3).toUInt()
            );

            blocksByName.insert(blk->name(), blk);
        }
        else
        {
            return false;
        }
    }

    return true;
}

BlocksMap::~BlocksMap()
{
    QMap<QString, Block*>::iterator iterator;
    for (iterator = blocksByName.begin(); iterator != blocksByName.end(); iterator++)
    {
        delete iterator.value();
    }
}

Block* BlocksMap::get(QString name)
{
    return blocksByName[name];
}
