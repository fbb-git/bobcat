#include "ofdstreambuf.ih"

void OFdStreambuf::open(int fd, Mode mode, size_t n)
{
    cleanup(mode);

    d_fd = fd;
    d_n = (n == 0) ? 1 : n;

    d_buffer = new char[d_n];
    setp(d_buffer, d_buffer + d_n);
}
