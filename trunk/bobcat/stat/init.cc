#include "stat.ih"

void Stat::init()
{
    d_errno = ::stat(d_name.c_str(), &d_stat) ? 
                    errno
                :
                    0;
}
