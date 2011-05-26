#include "cmdfinderbase.ih"

CmdFinderBase& CmdFinderBase::operator=(CmdFinderBase const &rhs)
{
    CmdFinderBase tmp(std::move(rhs));
    fswap(*this, tmp);
    return *this;
}
