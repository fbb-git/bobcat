#include "sharedstreambuf.hh"

std::streamsize SharedStreambuf::xsputn(char const *buf, std::streamsize len)
{
    return mode(ios::out) ? d_memory.write(buf, len) : EOF;
}
