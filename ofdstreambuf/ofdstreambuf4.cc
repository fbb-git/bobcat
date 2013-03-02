#include "ofdstreambuf.ih"

OFdStreambuf::OFdStreambuf(int fd, Mode mode, size_t n)
:
    d_mode(mode),
    d_buffer(0)
{
    open(fd, CLOSE_FD, n);
}

