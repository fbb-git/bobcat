#include "datetime.ih"

bool DateTime::updateTime(struct tm *tmPtr)
{
    time_t time = mktime(tmPtr);

    if (not breakDown(tmPtr, d_type, time))
        return false;

    d_time = time;
    d_tm = *tmPtr;
    return true;
}
