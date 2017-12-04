#ifndef FAULTSMAP_H
#define FAULTSMAP_H

#include <QString>
#include <QMap>

struct FaultsMap
{
public:
    FaultsMap();
    ~FaultsMap();

    bool loadFromFile(QString filepath);
    QString get(uint8_t faultCode);

private:
    QMap<uint8_t, QString> m_faultsMap;
};

#endif // FAULTSMAP_H
