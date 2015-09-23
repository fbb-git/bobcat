#include "ifdstreambuf.hh"

void IFdStreambuf::open(int xfd, Mode mode, size_t n)
{
    cleanup(mode);

    d_fd = xfd;
    d_n = (n == 0) ? 1 : n;

    d_buffer = new char[d_n];
    setg(d_buffer, d_buffer + d_n, d_buffer + d_n);
}
