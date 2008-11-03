#include "datetime.ih"

string DateTime::rfc3339() const
{
    ostringstream out;

    out <<             1900 + d_tm.tm_year << '-' << 
            setw(2) << d_tm.tm_month << '-' <<
            setw(2) << d_tm.tm_day << ' ' <<

     timeStr(out) << showpos << 
                        setw(3) << internal << -d_timezone / 3600 << 
                    noshowpos << 
                        setw(2) << abs(d_timezone) % 3600 / 60;

    return out.str();
}
