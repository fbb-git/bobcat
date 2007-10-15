#include "hostent.ih"

Hostent &Hostent::operator=(Hostent const &other)
{
    if (this != &other)
    {
        destroy();        
        copy(&other, other.d_nAliases, other.d_nAddresses);
    }
    return *this;
}
