#include "ofilterstreambuf.ih"

void OFilterStreambuf::open(char const *fname, openmode mode)
{
    sync();
    d_dest.open(fname, mode);
    d_out = &d_dest;
}

