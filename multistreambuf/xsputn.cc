#include "multistreambuf.hh"

std::streamsize MultiStreambuf::xsputn(char const *buffer, std::streamsize n)
{
    d_buffer.append(buffer, n);
    return n;
}
