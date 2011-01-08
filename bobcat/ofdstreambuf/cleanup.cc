#include "ofdstreambuf.ih"

void OFdStreambuf::cleanup(Mode mode)
{
    if (d_buffer)
    {
        sync();
        if (d_mode == CLOSE_FD)
            close(d_fd);
        delete [] d_buffer;
        d_buffer = 0;
    }
}
    
