#ifndef POLL_GROUP_H
#define POLL_GROUP_H

#include <QObject>
#include <QTimer>
#include <QVector>

#include "model/register.h"

class PollGroup : public QObject
{
    Q_OBJECT
public:
    explicit PollGroup(int pollInterval_ms, QObject *parent = 0);
    void enablePoll(bool);
    bool isPollEnabled() const;

signals:
    void onRead();
    void onReadError(request_error_t errorCode);

private slots:
    void performRead();
    void readReply();

private:
    void restartTimer();

    QVector<Register*> registers;

    QTimer* pollTimer;
    bool pollEnabled;
    int pollInterval;
};

#endif // POLL_GROUP_H
