#include "model/card_scanner.h"
#include "data/data.h"

CardScanner::CardScanner(QObject *parent) : QObject(parent)
{
    m_socket = new QUdpSocket(this);
    connect(m_socket, SIGNAL(readyRead()), this, SLOT(onDataReceivedUDP()));
    m_socket->bind(QHostAddress::Any, 7756);

    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(onTimeout()));
}

CardScanner::~CardScanner()
{
}

void CardScanner::onTimeout()
{
    emit onScanDone();
}

void CardScanner::scan(QNetworkInterface interface)
{
    char testDatagram[10];
    uint16_t status  = 0x0000; // raw
    uint16_t type    = 0x0001; // read
    uint16_t address = 0x4022; // test register
    uint32_t data    = 0x00000000; // data

    memcpy(testDatagram + 0, &status , 2);
    memcpy(testDatagram + 2, &type   , 2);
    memcpy(testDatagram + 4, &address, 2);
    memcpy(testDatagram + 6, &data   , 4);

    foreach (QNetworkAddressEntry entry, interface.addressEntries())
    {
        QHostAddress address = entry.broadcast();
        m_socket->writeDatagram(testDatagram, sizeof(testDatagram), address, DEFAULT_CONTROLLER_PORT);
    }

    m_timer->start(1000);
}

void CardScanner::onDataReceivedUDP()
{
    while (m_socket->hasPendingDatagrams())
    {
        QHostAddress sender;
        quint16 senderPort;

        char buffer[128];
        qint64 readSize = m_socket->readDatagram(buffer, sizeof(buffer), &sender, &senderPort);
        if (readSize == 10)
        {
            uint16_t address = 0x4022;
            if (memcmp(buffer + 4, &address, 2) == 0)
                emit onCardFound(sender.toString());
        }
    }
}
