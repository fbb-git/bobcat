#include "stat.ih"

string Stat::modeStr() const
{
    string ret = "rwxrwxrwx";

    size_t mode = d_stat.st_mode;

    for (size_t idx = 9; idx--; mode >>= 1)
    {
        if (!mode & 1)      // bit not set
            ret[idx] = '-';
    }

    if (d_stat.st_mode & SUID)
        ret[2] = ret[2] == 'x' ? 's' : 'S';

    if (d_stat.st_mode & SGID)
        ret[5] = ret[5] == 'x' ? 's' : 'S';

    if (d_stat.st_mode & SB)  
        ret[8] = ret[8] == 'x' ? 't' : 'T';

    return ret;
}


    
