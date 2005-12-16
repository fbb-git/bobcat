#include "process.ih"

unsigned Process::available()
{
    d_selector.setAlarm(0);
    return whichStream();
}
