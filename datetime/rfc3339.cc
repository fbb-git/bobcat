#include "datetime.hh"

string DateTime::rfc3339() const
{
    ostringstream out;

    out <<  setfill('0') <<
            1900 + d_tm.tm_year << '-' << 
            setw(2) << (d_tm.tm_mon + 1) << '-' <<
            setw(2) << d_tm.tm_mday << ' ';

     timeStr(out) << ' ' << 
                    showpos << setw(3) << internal <<
                            d_displayZoneShift / 3600 << 
                    ':' << noshowpos << setw(2) << 
                            abs(d_displayZoneShift) % 3600 / 60;

    return out.str();
}
