#include "datetime.ih"

bool DateTime::setYear(size_t year)
{
    TimeStruct tmStruct = d_tm;
    tmStruct.tm_year = year - 1900;

    return updateTime(&tmStruct);
}
