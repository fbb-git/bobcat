#include "datetime.ih"

// utcCorrection computes the correction by determining the difference between
// the current UTC time (from time(0)) and the recomputed UTC time from
// mktime(gmtime(time(0))). 

// Although time(0) represents the UTC time and gmtime() returns the
// TimeStruct correctly representing the UTC time, when mktime() is called
// with the return value of gmtime() the difference between the actual UTC
// time and the time returned by mktime() is not 0 but the time zone
// difference in seconds.

// Therefore, if a presumably UTC time representing TimeStruct is provided,
// calling mktime() on this struct will not return the matching UTC time, but
// a UTC time which must be corrected by the correction computed above.


time_t DateTime::utcCorrection(TimeStruct const *tsPar)
{
    time_t utc = ::time(0);

    TimeStruct ts;

    int correction = utc - mktime(gmtime_r(&utc, &ts));

    ts = *tsPar;

    return mktime(&ts) + correction;
}




