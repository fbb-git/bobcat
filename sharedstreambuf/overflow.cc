#include "sharedstreambuf.hh"

int SharedStreambuf::overflow(int ch)
{
    return mode(ios::out) ? d_memory.put(ch) : EOF;
}
