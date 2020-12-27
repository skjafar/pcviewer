#include "model/parameter_set.h"
#include <QFile>

Parameter::Parameter() :
    m_name(""), m_address(0), m_type(PARAMETER_TYPE_INTEGRAL), m_hex(false), m_uint(0)
{}

Parameter::Parameter(QString name, uint16_t address, ParameterType type, bool isHex) :
    m_name(name), m_address(address), m_type(type), m_hex(isHex), m_uint(0)
{}

ParameterDefinitions::ParameterDefinitions() : parameters()
{
}

bool ParameterDefinitions::loadFromFile(QString definitionsFile)
{
    QFile file(definitionsFile);
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
            Parameter parameter(
                /* name */    fields.at(1),
                /* address */ fields.at(0).toUInt(0, 16),
                /* type */    fields.at(2) == "int" || fields.at(2) == "hex" ? PARAMETER_TYPE_INTEGRAL : PARAMETER_TYPE_FLOATING,
                /* is hex */  fields.at(2) == "hex"
            );

            this->parameters.append(parameter);
        }
        else
        {
            return false;
        }
    }

    return true;
}

ParameterSet::ParameterSet(ParameterDefinitions *definitions, QObject *parent) : QObject(parent), parameters()
{
    QVector<Parameter>::const_iterator it;
    for (it = definitions->parameters.begin(); it < definitions->parameters.end(); it++)
    {
        Parameter *parameter = new Parameter(it->m_name, it->m_address, it->m_type, it->m_hex);
        parameters[parameter->m_name] = parameter;
    }
}

bool ParameterSet::loadFromBlockArray(const QByteArray &data)
{
    QMap<QString, Parameter *>::iterator it;
    for (it = parameters.begin(); it != parameters.end(); it++)
    {
        uint16_t address = it.value()->m_address;
        Q_ASSERT(address + sizeof(uint32_t) - 1 < (uint16_t) data.length());

        uint32_t value;
        memcpy(&value, data.data() + address * 4, sizeof(uint32_t));
        it.value()->m_uint = value;
    }

    emit onSetLoaded();
    return true;
}

bool ParameterSet::loadFromFile(QString filepath)
{
    QFile file(filepath);
    if (!file.open(QIODevice::ReadOnly)) return false; // TODO: add error handling?

    QTextStream stream(&file);

    while (!stream.atEnd())
    {
        // read comma separated values
        QString line = stream.readLine();

        if (line.isEmpty()) continue;
        if (line.startsWith("//") || line.startsWith("#")) continue;

        QStringList fields = line.split("=");
        if (fields.count() == 2)
        {
            QString name = fields.at(0).trimmed();
            if (!this->parameters.contains(name)) return false; // TODO: add error handling
            Parameter *parameter = this->parameters[name];

            if (parameter->m_type == PARAMETER_TYPE_INTEGRAL && !parameter->m_hex)
            {
                parameter->m_int = fields.at(1).trimmed().toLong();
            }
            else if (parameter->m_type == PARAMETER_TYPE_INTEGRAL && parameter->m_hex)
            {
                bool ok;
                parameter->m_int = fields.at(1).trimmed().toLong(&ok, 16);
            }
            else if (parameter->m_type == PARAMETER_TYPE_FLOATING)
            {
                parameter->m_float = fields.at(1).trimmed().toFloat();
                // uint temp = fields.at(1).trimmed().toUInt();
                // parameter->m_float= *(reinterpret_cast<float *>(&temp));
            }
        }
        else
        {
            return false; // TODO: add error handling?
        }
    }

    return true;
}

void ParameterSet::saveToFile(QString filepath)
{
    QFile file(filepath);
    if (!file.open(QIODevice::WriteOnly)) return;

    QTextStream stream(&file);

    QMap<QString, Parameter *>::const_iterator it;
    for (it = parameters.constBegin(); it != parameters.constEnd(); it++)
    {
        Parameter *parameter = it.value();
        stream << parameter->m_name << " = ";
        if (parameter->m_type == PARAMETER_TYPE_INTEGRAL && parameter->m_hex)
        {
            stream << "0x" << QString::number(parameter->m_int, 16);
        }
        else if (parameter->m_type == PARAMETER_TYPE_INTEGRAL && !parameter->m_hex)
        {
            stream << QString::number(parameter->m_int);
        }
        else if (parameter->m_type == PARAMETER_TYPE_FLOATING) // never reached because this is handled with the first if statement above to comply with CSS pf files
        {
            stream << QString::number(parameter->m_float);
        }
        stream << Qt::endl;
    }
}

void ParameterSet::saveToBlock(Block *block)
{
    QByteArray data(block->numberOfRegisters() * sizeof(uint32_t), '\0');

    QMap<QString, Parameter *>::const_iterator it;
    for (it = parameters.begin(); it != parameters.end(); it++)
    {
        uint16_t address = it.value()->m_address;
        Q_ASSERT(address + sizeof(uint32_t) - 1 < (uint16_t) data.length());
        memcpy(data.data() + address * 4, &it.value()->m_uint, sizeof(uint32_t));
    }

    block->write(data);
}

ParameterSet::~ParameterSet()
{
    QMap<QString, Parameter *>::iterator it;
    for (it = parameters.begin(); it != parameters.end(); it++)
    {
        delete it.value();
    }

    parameters.clear();
}

