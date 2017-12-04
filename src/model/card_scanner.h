#ifndef CARDSCANNER_H
#define CARDSCANNER_H

#include <QObject>
#include <QNetworkInterface>
#include <QUdpSocket>
#include <QTimer>

class CardScanner : public QObject
{
    Q_OBJECT

public:
    explicit CardScanner(QObject *parent = 0);
    ~CardScanner();

signals:
    void onCardFound(QString IP);
    void onScanDone();

public slots:
    void scan(QNetworkInterface);

private slots:
    void onDataReceivedUDP();
    void onTimeout();

private:
    QUdpSocket *m_socket;
    QTimer *m_timer;
};

#endif // CARDSCANNER_H
