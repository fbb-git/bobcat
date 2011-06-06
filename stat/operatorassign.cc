#include "stat.ih"

Stat &Stat::operator=(Stat &&tmp)
{
    fswap(*this, tmp);
    return *this;
}
