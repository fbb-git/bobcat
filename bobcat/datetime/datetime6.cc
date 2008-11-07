#include "datetime.ih"

DateTime::DateTime(TimeStruct const *ts, TimeType type)
:
    d_type(type),
    d_time(utcCorrection(ts)) 
{
    initializeTime(0, 0);
    breakDown();
}
