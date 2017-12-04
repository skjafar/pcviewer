#include "model/registers_map.h"

#include <QStringList>
#include <QFile>
#include <QTextStream>

RegistersMap::RegistersMap(Communicator* communicator) :
    communicator(communicator)
{
}

bool RegistersMap::loadFromFile(QString filepath)
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
        if (fields.count() == 3)
        {
            Register* reg = new Register(
                communicator,
                fields.at(0).toUInt(0, 16),
                fields.at(1),
                fields.at(2) == "int" || fields.at(2) == "hex" ? REGISTER_TYPE_INTEGRAL : REGISTER_TYPE_FLOATING,
                fields.at(2) == "hex"
            );

            registersByAddress.insert(reg->address(), reg);
            registersByName.insert(reg->name(), reg);
        }
        else
        {
            return false;
        }
    }

    return true;
}

RegistersMap::~RegistersMap()
{
    QMap<uint16_t, Register*>::iterator iterator;
    for (iterator = registersByAddress.begin(); iterator != registersByAddress.end(); iterator++)
    {
        delete iterator.value();
    }
}

Register* RegistersMap::get(QString name)
{
    return registersByName[name];
}

Register* RegistersMap::get(uint16_t address)
{
    return registersByAddress[address];
}
