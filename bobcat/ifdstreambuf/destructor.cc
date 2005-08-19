#include "ifdstreambuf.ih"

IFdStreambuf::~IFdStreambuf()
{
    if (d_buffer)
    {
        close(d_fd);
        delete d_buffer;
    }
}
