#include "stat.ih"

bool Stat::specialMode(size_t mode, Combine combi) const
{
    if (mode & ~(SUID | SGID | SB))
        throw Exception{1} << '0' << oct << mode << 
                                    ": unknown special mode specification";

    return (combi == ALL && mode == (d_stat.st_mode & (SUID | SGID | SB)))
           ||
           (combi == ANY && (mode & d_stat.st_mode));
}


    
