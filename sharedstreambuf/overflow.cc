#include "sharedstreambuf.ih"

int SharedStreambuf::overflow(int ch)
{
//cerr << "overflow\n";
    return mode(ios::out) ? d_memory.put(ch) : EOF;
}
