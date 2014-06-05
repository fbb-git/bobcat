#include "sharedstreambuf.ih"

int SharedStreambuf::overflow(int ch)
{
    return mode(ios::out) ? d_memory.put(ch) : EOF;
}
