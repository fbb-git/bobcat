#include "stat.ih"

Stat &Stat::operator=(Stat &&tmp)
{
    fswap(*this, tmp, d_name);
    return *this;
}
