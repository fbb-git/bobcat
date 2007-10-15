#include "datetime.ih"

// "Wed Jun 30 21:49:08 1993\n"
//  0                       ^
//                          24 
namespace std
{

ostream &operator<<(ostream &out, FBB::DateTime const &dt)
{
    char buf[26];           // Magical number provided by ctime's man-page

    asctime_r(&dt.d_tm, buf);

    buf[24] = 0;            // remove final \n
    return out << buf;
}

}

