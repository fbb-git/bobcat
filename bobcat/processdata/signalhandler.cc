#include "processdata.ih"

void ProcessData::signalHandler(size_t signal)
{
    if (d_action == MONITORING)
    {
        d_action = CHILD_ENDED;
        d_condition.notify_one();
    }
}
