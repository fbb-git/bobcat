#include "cidr.hh"

void Cidr::setCidr(std::string const &cidrPattern)
{
    d_cidr.clear();

    pushCidr(cidrPattern);
}
