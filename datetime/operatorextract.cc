#include "datetime.ih"

namespace std
{

istream &operator>>(istream &in, FBB::DateTime &dt)
{
    DateTime::TimeStruct timeStruct = dt.d_tm;
    time_t time = dt.d_time;

    dt.parse(in);

    dt.utcSec2timeStruct(&dt.d_tm, dt.d_time);

    if (!dt.d_ok)
    {
        dt.d_time = time;
        dt.d_tm = timeStruct;
        dt.d_ok = false;
    }

    return in;
    
}

}

