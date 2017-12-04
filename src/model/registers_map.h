#ifndef REGISTERSMAP_H
#define REGISTERSMAP_H

#include <QString>
#include <QMap>

#include "model/communicator.h"
#include "model/register.h"

struct RegistersMap
{
public:
    explicit RegistersMap(Communicator* communicator);
    ~RegistersMap();

    Register* get(QString name);
    Register* get(uint16_t address);

    bool loadFromFile(QString filepath);

    // TODO: remove from public interface and provide an iterator
    QMap<uint16_t, Register*> registersByAddress;
    QMap<QString, Register*> registersByName;

private:
    Communicator* communicator;
};

#endif // REGISTERSMAP_H
