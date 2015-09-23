#include "ohexstreambuf.hh"

OHexStreambuf::~OHexStreambuf()
{
    out().fill(d_padding);
    out().flags(d_current);
}
