#include "multistreambuf.hh"

int MultiStreambuf::sync()
{
    return pSync();
}

