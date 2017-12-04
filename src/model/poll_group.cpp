#include "model/poll_group.h"

PollGroup::PollGroup(int pollInterval_ms, QObject *parent) :
    QObject(parent),
    pollTimer(NULL),
    pollEnabled(false),
    pollInterval(pollInterval_ms)
{
    registers.clear();
}

void PollGroup::enablePoll(bool enable)
{
    if (enable)
    {
        if (!pollTimer)
        {
            pollTimer = new QTimer(this);
            pollTimer->setSingleShot(true);
            connect(pollTimer, SIGNAL(timeout()), this, SLOT(performRead()));
        }

        pollTimer->start(pollInterval);
    }
    else
    {
        if (pollTimer) pollTimer->stop();
    }

    pollEnabled = enable;
}

void PollGroup::performRead()
{

}

bool PollGroup::isPollEnabled() const
{
    return this->pollEnabled;
}

void PollGroup::restartTimer()
{
    if (pollEnabled) pollTimer->start(pollInterval);
}

void PollGroup::readReply()
{
    this->restartTimer();
}
