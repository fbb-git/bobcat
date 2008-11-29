#include "datetime.ih"

DateTime::DateTime(TimeStruct const &ts, TimeType type)
:
    d_type(type),
    d_dstShift(0)
{
    zoneCorrection();

    d_tm = ts;

    setDisplayZone();
    updateTime(&d_tm);
}
