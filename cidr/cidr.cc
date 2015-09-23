#include "cidr.hh"

string Cidr::cidr() const
{
    ostringstream out;
    out << binary2dotted(d_iter->first) << '/' << d_iter->second;
    return out.str();
}
