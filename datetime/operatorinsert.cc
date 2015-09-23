#include "datetime.hh"

// "Wed Jun 30 21:49:08 1993\n"
//  0                       ^
//                          24 
namespace FBB
{

std::ostream &operator<<(std::ostream &out, DateTime const &dt)
{
    char buf[26];           // Magical number provided by ctime's man-page

    asctime_r(&dt.d_tm, buf);

    buf[24] = 0;            // remove final \n
    return out << buf;
}

}

