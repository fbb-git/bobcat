#include "iostreambuf.hh"

std::streamsize IOStreambuf::xsputn(char const *buffer, streamsize n)
{
    return pXsputn(buffer, n);
}
