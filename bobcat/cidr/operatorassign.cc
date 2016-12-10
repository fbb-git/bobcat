#include "cidr.ih"

#include "../iuo/iuo"

Cidr &Cidr::operator=(Cidr &&tmp) 
{
    swap(tmp);
    return *this;
}
