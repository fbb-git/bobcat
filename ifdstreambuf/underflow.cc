#include "ifdstreambuf.ih"

int IFdStreambuf::underflow()
{
            // the static_cast<unsigned char> is required to prevent
            // promotions of 0xff characters to -1, thus returning EOF...

    if (gptr() < egptr())               
        return static_cast<unsigned char>(*gptr());

    int nread = read(d_fd, d_buffer, d_n);

    if (nread <= 0)
        return EOF;

    setg(d_buffer, d_buffer, d_buffer + nread);  
    return static_cast<unsigned char>(*gptr());
}
    
