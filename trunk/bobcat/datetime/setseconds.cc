#include "datetime.ih"

bool DateTime::setSeconds(int seconds)
{
    struct tm tmStruct = d_tm;
    tmStruct.tm_sec = seconds;

    return updateTime(&tmStruct);
}
