#include "cidr.ih"

#include "../iuo/iuo"

Cidr &Cidr::operator=(Cidr &&tmp) 
{
    fswap(*this, tmp);
    return *this;
}
