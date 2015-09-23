#include "tablebuf.hh"

int TableBuf::pSync()
{
    if (d_buffered)
        nextField();

    return 0;
}
