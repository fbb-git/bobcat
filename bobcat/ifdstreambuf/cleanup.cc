#include "ifdstreambuf.hh"

void IFdStreambuf::cleanup(Mode mode)
{
    if (d_buffer)
    {
        if (mode == CLOSE_FD)
            ::close(d_fd);

        delete [] d_buffer;
        d_buffer = 0;
        d_fd = -1;
    }
}
