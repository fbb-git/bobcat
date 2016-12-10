#include "cidr.ih"

void Cidr::swap(Cidr &rhs)
{
    fswap(*this, rhs, d_matched);
}
