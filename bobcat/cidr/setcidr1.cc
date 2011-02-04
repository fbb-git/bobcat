#include "cidr.ih"

void Cidr::setCidr(std::string const &cidrPattern)
{
    d_cidr.clear();
    d_cidr.push_back(parse(cidrPattern));
}
