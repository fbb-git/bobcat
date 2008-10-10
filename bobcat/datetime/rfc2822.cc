#include "datetime.ih"

string DateTime::rfc2822() const
{
    ostringstream out;
    out << *this << ' ' << 
            setfill('0') << showpos << 
                setw(3) << internal << -d_timezone / 3600 << 
            noshowpos << 
                setw(2) << abs(d_timezone) % 3600 / 60;

    return out.str();
}
