#include "cmdfinderbase.ih"

CmdFinderBase& CmdFinderBase::operator=(CmdFinderBase &&tmp)
{
    fswap(*this, tmp);
    return *this;
}
