#include "process.ih"

size_t Process::wait()
{
    d_selector.noAlarm();
    return whichStream();
}
