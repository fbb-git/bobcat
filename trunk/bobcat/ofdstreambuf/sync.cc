#include "ofdstreambuf.ih"

int OFdStreambuf::sync()
{
    if (pptr() > pbase())
    {
        write(d_fd, d_buffer, pptr() - pbase());    
        setp(d_buffer, d_buffer + d_n);             
    }
    return 0;
}
