#ifndef REGISTER_H
#define REGISTER_H

#include <QObject>

#include "model/communicator.h"
#include "model/request.h"
#include "model/register_poll.h"
#include "data/data.h"

class RegisterPoll;

enum RegisterType
{
    REGISTER_TYPE_INTEGRAL,
    REGISTER_TYPE_FLOATING
};

class Register : public QObject
{
    Q_OBJECT

public:
    explicit Register(Communicator* m_communicator, uint16_t address, QString name, RegisterType type, bool showAsHex = false, QObject *parent = 0);

    RegisterPoll* getPoller(int pollInterval_ms, QObject *parent = NULL);
    RegisterPoll* getPoller(QObject *parent = NULL);

    uint16_t address() const { return this->m_address; }
    QString name() const { return this->m_name; }
    RegisterType type() const { return this->m_type; }
    int32_t intVal() const { return this->m_int; }
    uint32_t uintVal() const { return this->m_uint; }
    float floatVal() const { return this->m_float; }
    bool valid() const { return this->m_valid; }
    Communicator *communicator() { return this->m_communicator; }

    QString toString() const;

    bool showAsHex;


signals:
    void onChange();
    void onReadReply();
    void onReadError(request_error_t errorCode);
    void onWriteError(request_error_t errorCode);
    void onError(request_error_t errorCode);

public slots:
    void read();

    void write(int32_t value);
    void write(uint32_t value);
    void write(float value);

private slots:
    void onReadReply(RegisterRequest*);
    void onReadError(RegisterRequest*, request_error_t);
    void onWriteError(RegisterRequest*, request_error_t);
    void onHandlingDone(RegisterRequest*);

private:
    uint16_t m_address;
    QString m_name;
    RegisterType m_type;

    bool m_valid;

    union
    {
        int32_t m_int;
        uint32_t m_uint;
        float m_float;
    };

    Communicator* m_communicator;
};

#endif // REGISTER_H
