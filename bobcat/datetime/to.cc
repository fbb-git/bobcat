#include "datetime.hh"

DateTime DateTime::to(TimeType type) const
{
    if (type == UTC)
        return DateTime(d_utcSec, UTC);

    if (d_displayZoneShift)
        return DateTime(d_utcSec + d_displayZoneShift, LOCALTIME);

    bool ok;
    return DateTime(d_utcSec + defaultDisplayZoneShift() + dstCorrection(&ok),
                    LOCALTIME);
}
