#include "ohexstreambuf.ih"

int OHexStreambuf::pSync()
{
    out() << flush;
    return 0;
}
