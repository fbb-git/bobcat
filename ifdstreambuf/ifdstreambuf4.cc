#include "ifdstreambuf.hh"

IFdStreambuf::IFdStreambuf(int fd, Mode mode, size_t n)
:
    d_mode(mode),
    d_buffer(0)
{
    open(fd, KEEP_FD, n);
}
