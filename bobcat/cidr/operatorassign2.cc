#include "cidr.ih"

#include "../iuo/iuo"

Cidr &Cidr::operator=(Cidr const &&tmp) 
{
    static bool called = false;
    deprecated__(called, "Cidr::operator=(Cidr const &&tmp)");

    fswap(*this, const_cast<Cidr &>(tmp));
    return *this;
}
