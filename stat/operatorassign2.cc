#include "stat.ih"

#include "../iuo/iuo"

Stat &Stat::operator=(Stat const &&tmp)
{
    static bool called = false;
    deprecated__(called, "Stat::operator=(Stat const &&tmp)");

    fswap(*this, const_cast<Stat &>(tmp));
    return *this;
}
