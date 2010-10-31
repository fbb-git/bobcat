#include "tablebuf.ih"

int TableBuf::pSync()
{
    if (d_buffered)
        nextField();

    return 0;
}
