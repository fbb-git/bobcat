inline DateTime DateTime::timeZoneShift(int displayZoneShift) const
{
    return DateTime(d_utcSec, displayZoneShift);
}
