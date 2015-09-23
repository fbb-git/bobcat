#include "processdata.hh"

void ProcessData::signalHandler(size_t signal)
{
    if (d_action == TIME_LIMIT)
    {
        d_action = CHILD_ENDED;
        d_condition.notify_one();
    }
}
