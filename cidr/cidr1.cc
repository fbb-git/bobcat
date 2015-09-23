#include "cidr.hh"

Cidr::Cidr(std::string const &cidrPattern)
{
    pushCidr(cidrPattern);
}
