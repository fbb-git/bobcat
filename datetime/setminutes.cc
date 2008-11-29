#include "datetime.ih"

bool DateTime::setMinutes(int minutes)
{
    struct tm tmStruct = d_tm;
    tmStruct.tm_min = minutes;

    return updateTime(&tmStruct);
}
