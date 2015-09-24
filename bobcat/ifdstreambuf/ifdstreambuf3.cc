#include "ifdstreambuf.ih"

IFdStreambuf::IFdStreambuf(int fd, size_t n)
:
    d_mode(KEEP_FD),        // comply with old default
    d_buffer(0)
{
    open(fd, KEEP_FD, n);
}
