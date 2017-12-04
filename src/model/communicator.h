#ifndef COMMUNICATOR_H
#define COMMUNICATOR_H

#include <QObject>
#include <QQueue>
#include <QUdpSocket>
#include <QTcpSocket>
#include <QTimer>

#include "model/request.h"

#define TIMEOUT_THRESHOLD 3

class Communicator : public QObject
{
    Q_OBJECT

public:
    explicit Communicator(QString ip, short port, QObject *parent = 0);

    void queueRequest(SomeRequest request);
    void reconnect();

    QString controllerIP() const { return m_ip; }
    short controllerPort() const { return m_port; }

signals:

public slots:

private slots:
    void onDataReceivedUDP();
    void onDataReceivedTCP();
    void onTimeout();

private:
    void processHead();

    QString m_ip;
    short m_port;
    int m_timeout;

    QQueue<SomeRequest> m_requests;
    QUdpSocket *m_udpSocket;
    QTcpSocket *m_tcpSocket;
    QTimer* m_timeoutTimer;
    int m_timeoutCount;
    bool m_frontProcessed;
};

#endif // COMMUNICATOR_H
