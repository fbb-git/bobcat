#include "tablebuf.ih"

int TableBuf::sync()
{
    if (d_buffered)
        nextField();

    return 0;
}
