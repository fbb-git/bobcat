#include "ifdstreambuf.hh"

std::streamsize IFdStreambuf::xsgetn(char *dest, std::streamsize n)
{
    if (n == 0)
        return 0;

    // this function is called from istream's read() member. 
    // it copies what's available in the IFdStreambuf's own buffer and
    // will then try to read some more from the fd, adding it to the
    // destination buffer. Unless the requested amount of information is
    // available the stream's good() member will return false. Calling
    // programs may have to clear the stream's flags when, e.g., 
    // at least one byte was read
    
    int avail = egptr() - gptr();

    if (avail > n)
        avail = n;

    memcpy(dest, gptr(), avail);
    gbump(avail);                       

    return avail + read(d_fd, dest + avail, n - avail);
}

