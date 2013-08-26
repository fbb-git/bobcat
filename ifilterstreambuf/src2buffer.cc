#include "ifilterstreambuf.ih"

void IFilterStreambuf::src2buffer(size_t nBytes)
{
    memcpy(d_end, d_srcBegin, nBytes);
    d_srcBegin += nBytes;
    d_next = d_end;
    d_end += nBytes;
    d_remaining -= nBytes;
}
