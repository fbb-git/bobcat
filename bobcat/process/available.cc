#include "process.ih"

size_t Process::available()
{
    d_selector.setAlarm(0);
    return whichStream();
}
