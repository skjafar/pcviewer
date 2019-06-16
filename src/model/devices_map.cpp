#include "devices_map.h"

#include <QStringList>
#include <QFile>
#include <QTextStream>

DevicesMap::DevicesMap() : m_devicesMap()
{}

DevicesMap::~DevicesMap()
{}

bool DevicesMap::loadFromFile(QString filepath)
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
        if (fields.count() == 2)
        {
            uint32_t key = fields[0].toInt(NULL, 0);
            m_devicesMap.insert(key, fields[1]);
        }
        else
        {
            return false;
        }
    }

    return true;
}

QString DevicesMap::get(uint32_t deviceID)
{
    QMap<uint32_t, QString>::const_iterator it = m_devicesMap.find(deviceID);
    if (it == m_devicesMap.end()) return "IP not defined";
    else return it.value();
}
