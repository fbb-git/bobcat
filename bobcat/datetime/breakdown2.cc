#include "datetime.ih"

bool DateTime::breakDown(struct tm *tmStruct)
{
    time_t time = d_time - d_zoneShift + d_displayZone; // get back to utc
                                                        // then add local time
                                                        // shift

    cout << d_zoneShift << " " << d_displayZone << endl;
    return gmtime_r(&time, tmStruct);
}
