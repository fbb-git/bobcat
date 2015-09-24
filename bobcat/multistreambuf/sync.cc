#include "multistreambuf.ih"

int MultiStreambuf::sync()
{
    return pSync();
}

