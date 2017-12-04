#ifndef PARAMETERSET_H
#define PARAMETERSET_H

#include <QObject>
#include <QString>
#include <QStringList>
#include <QVector>
#include <QByteArray>
#include <QMap>

#include "model/block.h"

enum ParameterType
{
    PARAMETER_TYPE_INTEGRAL,
    PARAMETER_TYPE_FLOATING
};

struct Parameter
{
    explicit Parameter();
    explicit Parameter(QString name, uint16_t address, ParameterType type, bool isHex);

    QString m_name;
    uint16_t m_address;
    ParameterType m_type;
    bool m_hex;

    union
    {
        int32_t m_int;
        uint32_t m_uint;
        float m_float;
    };
};

struct ParameterDefinitions
{
    explicit ParameterDefinitions();
    bool loadFromFile(QString definitionsFile);
    QVector<Parameter> parameters;
};

class ParameterSet : public QObject
{
    Q_OBJECT
public:
    explicit ParameterSet(ParameterDefinitions *definitions, QObject *parent = 0);
    ~ParameterSet();

    QMap<QString, Parameter *> parameters; // Todo: move to private and provide iterator

signals:
    void onSetLoaded();

public slots:
    bool loadFromFile(QString filepath);
    bool loadFromBlockArray(const QByteArray &data);
    void saveToFile(QString filepath);
    void saveToBlock(Block *block);

private:
};

#endif // PARAMETERSET_H
