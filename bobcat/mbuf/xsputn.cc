#include "mbuf.ih"

std::streamsize Mbuf::xsputn(char const *buf, std::streamsize n)
{
    atFirstChar();
    d_ostr.write(buf, n);
    return n;               // only if the write succeeded
}
