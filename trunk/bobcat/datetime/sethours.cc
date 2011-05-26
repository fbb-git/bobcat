#include "datetime.ih"

// since localtime() and mktime() return each other's inverses, use
// localtime() to determine the new # seconds.

bool DateTime::setHours(int hours)
{
    TimeStruct ts = d_tm; // d_tm represents the time as displayed
                                // in the current display zone shift

    ts.tm_hour = hours;   // update the hour value  

    return updateTime(ts);
}



