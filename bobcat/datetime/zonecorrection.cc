#include "datetime.ih"

void DateTime::zoneCorrection()
{
    if (s_zoneCorrection == INT_MAX)
    {
        TimeStruct ts;

        time_t utc = ::time(0);
        s_zoneCorrection = utc - mktime(gmtime_r(&utc, &ts));
    }
}
