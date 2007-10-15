#include "process.ih"

size_t Process::wait(size_t sec, size_t msec)
{
    d_selector.setAlarm(sec, msec);
    return whichStream();
}
