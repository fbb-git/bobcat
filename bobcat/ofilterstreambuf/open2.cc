#include "ofilterstreambuf.hh"

void OFilterStreambuf::open(std::string const &fname, openmode mode)
{
    sync();
    d_dest.open(fname, mode);
    d_out = &d_dest;
}

