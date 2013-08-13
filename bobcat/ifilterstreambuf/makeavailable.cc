#include "ifilterstreambuf.ih"

void IFilterStreambuf::makeAvailable(size_t nBytes)
{
    memmove(d_begin, d_begin + nBytes, d_bufSize - nBytes);
    d_end -= nBytes;
    d_next = d_end;
    d_remaining += nBytes;

    src2buffer(nBytes);
}
