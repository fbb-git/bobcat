#include "process.ih"

unsigned Process::wait(unsigned sec, unsigned msec)
{
    d_selector.setAlarm(sec, msec);
    return whichStream();
}
