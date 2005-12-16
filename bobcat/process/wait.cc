#include "process.ih"

unsigned Process::wait()
{
    d_selector.noAlarm();
    return whichStream();
}
