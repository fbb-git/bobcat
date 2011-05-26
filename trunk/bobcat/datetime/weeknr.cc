#include "datetime.ih"

size_t DateTime::weekNr() const
{
    TimeStruct tmStruct;
    tmStruct.tm_mon = 0;
    tmStruct.tm_mday = 1;

    DateTime jan1(*this);
    jan1.setFields(tmStruct, MONTH | MONTHDAY);

    return 1 + (jan1.d_tm.tm_wday + d_tm.tm_yday) / 7;
}
