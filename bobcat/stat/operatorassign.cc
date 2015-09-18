#include "stat.hh"

Stat &Stat::operator=(Stat &&tmp)
{
    fswap(*this, tmp);
    return *this;
}
