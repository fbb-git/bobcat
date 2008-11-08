#include "datetime.ih"

DateTime::DateTime(TimeStruct const *ts, TimeType type)
:
    d_type(type),
    d_time(timeStruct2utcSec(ts)) 
{
    initializeTime(0, 0);
    utcSec2timeStruct(&d_tm, time);
}
