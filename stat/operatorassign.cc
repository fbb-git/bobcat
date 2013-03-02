#include "stat.ih"

Stat &Stat::operator=(Stat const &&tmp)
{
    fswap(*this, const_cast<Stat &>(tmp));
    return *this;
}
