#include "datetime.hh"

string DateTime::rfc2822() const
{
    ostringstream out;

    out << s_day[d_tm.tm_wday] << ", " << setfill('0') << setw(2) <<
            d_tm.tm_mday << ' ' << s_month[d_tm.tm_mon] << ' ' <<
            1900 + d_tm.tm_year << ' ';

    timeStr(out) << ' ' <<
            showpos << 
                setw(3) << internal << 
                            d_displayZoneShift / 3600 << 
            noshowpos << 
                setw(2) << abs(d_displayZoneShift) % 3600 / 60;

    return out.str();
}
