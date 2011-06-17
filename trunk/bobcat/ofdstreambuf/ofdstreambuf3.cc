#include "ofdstreambuf.ih"

OFdStreambuf::OFdStreambuf(int fd, size_t n)
:
    d_mode(CLOSE_FD),
    d_buffer(0)
{
    open(fd, CLOSE_FD, n);
}

