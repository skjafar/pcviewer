#include <QUdpSocket>

#include "model/communicator.h"

Communicator::Communicator(QString ip, short port, QObject *parent) :
    QObject(parent), m_ip(ip), m_port(port), m_timeoutCount(0), m_frontProcessed(false)
{
    m_udpSocket = new QUdpSocket(this);
    connect(m_udpSocket, SIGNAL(readyRead()), this, SLOT(onDataReceivedUDP()));
    m_udpSocket->bind(QHostAddress::Any, 7755);

    m_tcpSocket = new QTcpSocket(this);
    connect(m_tcpSocket, SIGNAL(readyRead()), this, SLOT(onDataReceivedTCP()));
    m_tcpSocket->connectToHost(QHostAddress(m_ip), m_port);

    m_timeoutTimer = new QTimer(this);
    m_timeoutTimer->setSingleShot(true);
    connect(m_timeoutTimer, SIGNAL(timeout()), this, SLOT(onTimeout()));
}

void Communicator::reconnect()
{
    if (m_udpSocket) delete m_udpSocket;

    m_udpSocket = new QUdpSocket(this);
    connect(m_udpSocket, SIGNAL(readyRead()), this, SLOT(onDataReceivedUDP()));
    m_udpSocket->bind(QHostAddress::Any, 7755);

    if (m_tcpSocket) delete m_tcpSocket;

    m_tcpSocket = new QTcpSocket(this);
    connect(m_tcpSocket, SIGNAL(readyRead()), this, SLOT(onDataReceivedTCP()));
    m_tcpSocket->connectToHost(QHostAddress(m_ip), m_port);
}

void Communicator::queueRequest(SomeRequest request)
{
    bool processNext = m_requests.empty();

    m_requests.enqueue(request);
    if (processNext) this->processHead();
}

void Communicator::onDataReceivedUDP()
{
    while (m_udpSocket->hasPendingDatagrams())
    {
        m_timeoutCount = 0;
        m_timeoutTimer->stop();

        if (m_requests.empty() || m_requests.front().type() != SomeRequestType_Register)
        {
            QHostAddress sender;
            quint16 senderPort;
            char bbuffer[2048]; // maximum required should be 1094
            qint64 readSize = m_udpSocket->readDatagram(bbuffer, sizeof(bbuffer), &sender, &senderPort);
            qWarning("Received UDP data while not expecting any (size = %lld)", readSize);

            break;
        }

        RegisterRequest* request = m_requests.dequeue().getRegisterRequest();
        m_frontProcessed = false;

        QHostAddress sender;
        quint16 senderPort;

        char buffer[2048]; // maximum required should be 1094
        qint64 readSize = m_udpSocket->readDatagram(buffer, sizeof(buffer), &sender, &senderPort);
        Q_ASSERT(readSize == request->remainingBytes());

        SomeRequest nextRequest = request->handleResponse(buffer, readSize);
        if (nextRequest.type() != SomeRequestType_None) // This implements chained requests
        {
            m_requests.push_front(nextRequest);
            m_frontProcessed = false;
        }
    }

    if (!m_requests.empty()) this->processHead();
}

void Communicator::onDataReceivedTCP()
{
    while (m_tcpSocket->bytesAvailable())
    {
        m_timeoutCount = 0;
        m_timeoutTimer->stop();

        if (m_requests.empty() || m_requests.front().type() != SomeRequestType_Block)
        {
            char buffer[2048];
            qint64 bytesRead = m_tcpSocket->read(buffer, sizeof(buffer));
            qWarning("Received TCP data while not expecting any (size = %lld)", bytesRead);

            break;
        }

        BlockRequest* request = m_requests.front().getBlockRequest();

        char buffer[2048];
        qint64 bytesRemaining = request->remainingBytes();
        qint64 bytesRead = m_tcpSocket->read(buffer, sizeof(buffer) > (size_t) bytesRemaining ? bytesRemaining : sizeof(buffer));
        request->appendBytes(buffer, bytesRead);
        bytesRemaining -= bytesRead;

        if (bytesRemaining == 0)
        {
            // NOTE: code duplicated below
            m_requests.dequeue();
            m_frontProcessed = false;

            SomeRequest nextRequest = request->handleResponse();
            if (nextRequest.type() != SomeRequestType_None) // This implements chained requests
            {
                m_requests.push_front(nextRequest);
                m_frontProcessed = false;
            }

            if (!m_requests.empty()) this->processHead();
        }
        else
        {
            // restart timer until next reception
            // this means that at least some data must be received
            // during the timeout and that it is not necessary for
            // the whole response to be received within one timeout
            // interval
            m_timeoutTimer->start(m_requests.front().timeout());
        }
    }
}

void Communicator::processHead()
{
    SomeRequest request = m_requests.head();
    if (m_frontProcessed) return;
    m_frontProcessed = true;

    if (request.type() == SomeRequestType_Register)
    {
        RegisterRequest* registerRequest = request.getRegisterRequest();
        char* message = registerRequest->getMessage();
        m_udpSocket->writeDatagram(message, registerRequest->messageLength(), QHostAddress(m_ip), m_port);
        registerRequest->freeMessage(message);
    }
    else if (request.type() == SomeRequestType_Block)
    {
        BlockRequest* blockRequest = request.getBlockRequest();

        qint64 messageLength = blockRequest->messageLength();
        qint64 bytesSent = 0;

        char* message = blockRequest->getMessage();

        while (bytesSent < messageLength)
        {
            qint64 result = m_tcpSocket->write(message + bytesSent, messageLength - bytesSent);
            if (result == -1)
            {
                // TODO: handle send error
                Q_ASSERT(result != -1);
            }
            else
            {
                bytesSent += result;
            }
        }

        blockRequest->freeMessage(message);
        if (blockRequest->remainingBytes() == 0)
        {
            m_requests.dequeue();
            m_frontProcessed = false;

            SomeRequest nextRequest = blockRequest->handleResponse();
            if (nextRequest.type() != SomeRequestType_None) // This implements chained requests
            {
                m_requests.push_front(nextRequest);
                m_frontProcessed = false;
            }

            if (!this->m_requests.empty()) this->processHead();
            return;
        }
    }
    else
    {
        Q_ASSERT(0);
    }

    m_timeoutTimer->start(request.timeout());
}

void Communicator::onTimeout()
{
    // TODO: consider invalidating all pending requests
    SomeRequest request = m_requests.dequeue();
    m_frontProcessed = false;

    if (request.type() == SomeRequestType_Register)
    {
        request.getRegisterRequest()->onTimeout();
    }
    else if (request.type() == SomeRequestType_Block)
    {
        request.getBlockRequest()->onTimeout();
    }

    m_timeoutCount++;

    if (m_timeoutCount == TIMEOUT_THRESHOLD)
    {
        reconnect();
        m_timeoutCount = 0;
    }

    if (!m_requests.empty()) this->processHead();
}
