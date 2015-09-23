#include "ifilterstreambuf.hh"

std::streamsize IFilterStreambuf::showmanyc()
{
    return d_srcEnd - d_srcBegin;
}
