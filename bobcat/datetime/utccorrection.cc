#include "datetime.ih"

struct tm *DateTime::utcCorrection(struct tm &ts)
{
    struct tm stm;
    time_t utc = ::time(0);

    ts.tm_sec += utc - mktime(gmtime_r(&utc, &stm)); 

    return &ts;
}
