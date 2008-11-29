#include "datetime.ih"

void DateTime::zoneCorrection()
{
    if (s_currentZoneCorrection == INT_MAX)
    {
        TimeStruct ts;

        time_t utc = ::time(0);
        s_currentZoneCorrection = utc - mktime(gmtime_r(&utc, &ts));
    }
}
