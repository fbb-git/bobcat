#include "iostreambuf.hh"

streambuf::pos_type IOStreambuf::seekoff(off_type offset, 
                                    ios::seekdir way, ios::openmode mode)
{
    return pSeekoff(offset, way, mode);
}
