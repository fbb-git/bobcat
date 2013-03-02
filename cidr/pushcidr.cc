#include "cidr.ih"

void Cidr::pushCidr(string const &cidrPattern, Cidr &cidr)
{
    MaskPair spec = cidr.parse(cidrPattern);
    if (spec.second)
        cidr.d_cidr.push_back(spec);
}
