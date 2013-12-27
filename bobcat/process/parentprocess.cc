#include "process.ih"

void Process::parentProcess()   // overrides
{
    d_child.pid = pid();
    if (not d_data->parentProcess(d_timeLimit))
        stop();
}

