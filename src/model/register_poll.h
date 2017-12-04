#ifndef REGISTER_POLL_H
#define REGISTER_POLL_H

#include <QObject>
#include <QTimer>

#include "model/register.h"
class Register;

class RegisterPoll : public QObject
{
    Q_OBJECT
public:
    explicit RegisterPoll(Register* register_, int pollInterval_ms, QObject *parent = 0);
    void enablePoll(bool);
    bool isPollEnabled() const;

private slots:
    void readReply();

private:
    void restartTimer();

    Register* register_;
    QTimer* pollTimer;
    bool pollEnabled;
    int pollInterval;
};

#endif // REGISTER_POLL_H
