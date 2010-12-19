#include "cmdfinderbase.ih"

CmdFinderBase& CmdFinderBase::operator=(CmdFinderBase const &rhs)
{
    CmdFinderBase tmp(rhs);
    fswap(*this, tmp);
    return *this;
}
