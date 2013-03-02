#include "datetime.ih"

namespace std
{

ostream &operator<<(ostream &out, FBB::DateTime const &dt)
{
    char buf[26];           // Magical number provided by ctime's man-page

    asctime_r(&dt.d_tm, buf);

    buf[25] = 0;            // remove final \n
    return out << buf;
}

}

