#include "multistreambuf.hh"

int MultiStreambuf::overflow(int c)
{
    if (c == EOF)
        pSync();
    else 
        d_buffer += c;

    return c;
}

