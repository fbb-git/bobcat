#include "ifdstreambuf.ih"

void IFdStreambuf::cleanup(Mode mode)
{
    if (mode == CLOSE_FD)
        close(d_fd);

    if (d_buffer)
        delete [] d_buffer;
}
