#include "cidr.ih"

Cidr::Cidr(std::string const &cidrPattern)
{
    pushCidr(cidrPattern, *this);
}
