#ifndef DEVICES_MAP_H
#define DEVICES_MAP_H

#include <QObject>

#include <QString>
#include <QMap>

struct DevicesMap
{
public:
    DevicesMap();
    ~DevicesMap();

    bool loadFromFile(QString filepath);
    QString get(uint32_t deviceID);

private:
    QMap<uint32_t, QString> m_devicesMap;
};

#endif // DEVICES_MAP_H
