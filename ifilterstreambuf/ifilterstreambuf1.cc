#include "ifilterstreambuf.hh"

IFilterStreambuf::IFilterStreambuf(size_t bufSize)
:
    d_bufSize(bufSize < 100 ? 100 : bufSize),
    d_maxRefresh(d_bufSize >> 1),
    d_remaining(d_bufSize),
    d_buffer(new char[d_bufSize]),
    d_begin(d_buffer.get()),
    d_next(d_begin),
    d_end(d_begin)
{
    setg(0, 0, 0);
}
