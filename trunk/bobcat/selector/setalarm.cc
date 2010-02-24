#include "selector.ih"

void Selector::setAlarm(int sec, int usec)
{
    d_alarm.tv_sec  = sec;
    d_alarm.tv_usec = usec;

    long long testTime = usec + 1000000LL * sec;
    if (testTime < 0 || testTime > INT_MAX * 1000000LL)
        throw Errno(1, "Selector::setAlarm()");
}
