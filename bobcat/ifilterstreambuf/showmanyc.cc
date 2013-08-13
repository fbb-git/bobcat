#include "ifilterstreambuf.ih"

std::streamsize IFilterStreambuf::showmanyc()
{
    return d_srcEnd - d_srcBegin;
}
