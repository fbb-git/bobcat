#include "cidr.hh"

void Cidr::pushCidr(string const &cidrPattern)
{
    MaskPair spec = parse(cidrPattern);
    if (spec.second)
        d_cidr.push_back(spec);
}
