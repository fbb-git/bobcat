#include "datetime.ih"

bool DateTime::setSeconds(int seconds)
{
    if (!d_ok)
        return false;

    struct tm tmStruct = d_tm;
    tmStruct.tm_sec = seconds;

    return updateTime(&tmStruct);
}
