#include "model/card_scanner.h"
#include "data/data.h"

CardScanner::CardScanner(QObject *parent) : QObject(parent)
{
    m_socket = new QUdpSocket(this);
    connect(m_socket, SIGNAL(readyRead()), this, SLOT(onDataReceivedUDP()));
    m_socket->bind(QHostAddress::AnyIPv4, 7756);

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
    uint16_t address = DPC_CC_ID_REGISTER; // DPC_CC_ID Register
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
        uint32_t DPC_CC_ID;
        char buffer[128];

        qint64 readSize = m_socket->readDatagram(buffer, sizeof(buffer), &sender, &senderPort);

        if (readSize == 10)
        {
            uint16_t address = DPC_CC_ID_REGISTER;
            if (memcmp(buffer + 4, &address, 2) == 0)
            {
                memcpy(&DPC_CC_ID, buffer + 6, 4);
                emit onCardFound(sender.toString(), DPC_CC_ID);
            }
        }
    }
}
