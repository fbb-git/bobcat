#include "cidr.ih"

Cidr &Cidr::operator=(Cidr const &&tmp) 
{
    fswap(*this, const_cast<Cidr &>(tmp));
    return *this;
}
