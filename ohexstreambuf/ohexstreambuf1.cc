#include "ohexstreambuf.hh"

OHexStreambuf::OHexStreambuf(std::ostream &out, size_t width)
:
    OFilterStreambuf(out),
    d_current(out.flags()),
    d_padding(out.fill('0')),
    d_width(width),
    d_count(0)
{
    out << hex;
}

