#include "model/register_poll.h"

RegisterPoll::RegisterPoll(Register* register_, int pollInterval_ms, QObject *parent) :
    QObject(parent),
    register_(register_),
    pollTimer(NULL),
    pollEnabled(false),
    pollInterval(pollInterval_ms)
{
    connect(register_, SIGNAL(onReadReply()), this, SLOT(readReply()));
}

void RegisterPoll::enablePoll(bool enable)
{
    if (enable)
    {
        if (!pollTimer)
        {
            pollTimer = new QTimer(this);
            pollTimer->setSingleShot(true);
            connect(pollTimer, SIGNAL(timeout()), this->register_, SLOT(read()));
        }

        pollTimer->start(pollInterval);
    }
    else
    {
        if (pollTimer) pollTimer->stop();
    }

    pollEnabled = enable;
}

bool RegisterPoll::isPollEnabled() const
{
    return this->pollEnabled;
}

void RegisterPoll::restartTimer()
{
    if (pollEnabled) pollTimer->start(pollInterval);
}

void RegisterPoll::readReply()
{
    this->restartTimer();
}
