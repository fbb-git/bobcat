#include "cidr.hh"

string Cidr::binary2dotted(size_t binary)
{
    ostringstream out;

    out << 
        (binary >> 24 & 0xff) << '.' <<
        (binary >> 16 & 0xff) << '.' <<
        (binary >>  8 & 0xff) << '.' <<
        (binary       & 0xff);

    return out.str();
}
