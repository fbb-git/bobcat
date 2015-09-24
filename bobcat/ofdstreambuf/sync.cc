#include "ofdstreambuf.ih"

int OFdStreambuf::sync()
{
    if (pptr() > pbase())
    {
        if (write(d_fd, d_buffer, pptr() - pbase()) < 0)
            std::cerr << "[Warning] OFdStreambuf::sync could not "
                            "write to FD " << d_fd << '\n';

        setp(d_buffer, d_buffer + d_n);             
    }
    return 0;
}
