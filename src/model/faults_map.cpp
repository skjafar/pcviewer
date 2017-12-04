#include "model/faults_map.h"

#include <QStringList>
#include <QFile>
#include <QTextStream>

FaultsMap::FaultsMap() : m_faultsMap()
{}

FaultsMap::~FaultsMap()
{}

bool FaultsMap::loadFromFile(QString filepath)
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
            uint8_t key = fields[0].toInt(NULL, 0);
            m_faultsMap.insert(key, fields[1]);
        }
        else
        {
            return false;
        }
    }

    return true;
}

QString FaultsMap::get(uint8_t faultCode)
{
    QMap<uint8_t, QString>::const_iterator it = m_faultsMap.find(faultCode);
    if (it == m_faultsMap.end()) return "";
    else return it.value();
}
