#include "sharedstreambuf.hh"

ios::pos_type SharedStreambuf::seekpos(ios::pos_type offset, 
                                       ios::openmode mode)
{
    return seekoff(offset, ios::beg, mode);
}
