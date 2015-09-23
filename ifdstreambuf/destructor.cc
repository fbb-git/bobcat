#include "ifdstreambuf.hh"

IFdStreambuf::~IFdStreambuf()
{
    cleanup(d_mode);
}

