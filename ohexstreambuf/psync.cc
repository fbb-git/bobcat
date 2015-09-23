#include "ohexstreambuf.hh"

int OHexStreambuf::pSync()
{
    out() << flush;
    return 0;
}
