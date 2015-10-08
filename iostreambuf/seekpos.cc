#include "iostreambuf.ih"

IOStreambuf::pos_type IOStreambuf::seekpos(pos_type offset, 
                                           ios::openmode mode)
{
    return pSeekpos(offset, mode);
}

