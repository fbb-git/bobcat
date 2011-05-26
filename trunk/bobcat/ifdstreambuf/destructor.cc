#include "ifdstreambuf.ih"

IFdStreambuf::~IFdStreambuf()
{
    cleanup(d_mode);
}

