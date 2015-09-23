#include "datetime.hh"

namespace FBB
{

std::istream &operator>>(std::istream &in, DateTime &dt)
{
    DateTime::TimeStruct timeStruct = dt.d_tm;
    time_t time = dt.d_utcSec;

    dt.parse(in);

    dt.utcSec2timeStruct(&dt.d_tm, dt.d_utcSec);

    if (!dt.d_ok)
    {
        dt.d_utcSec = time;
        dt.d_tm = timeStruct;
        dt.d_ok = false;
    }

    return in;
}

}

