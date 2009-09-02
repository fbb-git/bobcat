#include "ohexstreambuf.ih"

int OHexStreambuf::sync()
{
    out() << flush;
    return 0;
}
