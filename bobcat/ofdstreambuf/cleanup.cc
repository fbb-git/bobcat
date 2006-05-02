#include "ofdstreambuf.ih"

void OFdStreambuf::cleanup(Mode mode)
{
    if (d_buffer)
    {
        sync();
        delete d_buffer;
    }

    if (d_mode == CLOSE_FD)
        close(d_fd);
}
    
