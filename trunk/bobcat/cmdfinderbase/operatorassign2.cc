#include "cmdfinderbase.ih"

CmdFinderBase& CmdFinderBase::operator=(CmdFinderBase const &&tmp)
{
    fswap(*this, const_cast<CmdFinderBase &>(tmp));
    return *this;
}
