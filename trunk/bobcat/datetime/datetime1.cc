#include "datetime.ih"

// Determine current UTC or LOCALTIME

DateTime::DateTime(TimeType type)
:
    d_type(type),
    d_utcSec(::time(0))
{
    setDisplayZone(defaultDisplayZoneShift()
                    + dstCorrection());         // displayZoneCorrection for 
                                                // `type'
    utcSec2timeStruct(&d_tm, d_utcSec);
}





