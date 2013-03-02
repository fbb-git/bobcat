#include "datetime.ih"

time_t DateTime::timeStruct2utcSec(TimeStruct *ts)
{
    time_t time = mktime(ts);

    if (time == -1)
    {
        d_ok = false;
        return 0;
    }

    d_ok = true;
    return time;
}
