#include "sharedstreambuf.ih"

int SharedStreambuf::underflow()
{
    return mode(ios::in) ? d_memory.get() : EOF;
}
