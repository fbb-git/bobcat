#include "stat.ih"

bool Stat::mode(size_t mode, Combine combi) const
{
    if (mode & ~(UR | UW | UX | RWX))
        throw Errno(1) << insertable <<
                "0" << oct << mode << ": unknown mode specification" <<
                throwable;

    return
        combi == ALL && mode == (d_stat.st_mode & RWX)
    ||
        combi == ANY && (mode & d_stat.st_mode);
}


    
