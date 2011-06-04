#include "cmdfinderbase.ih"

#include "../iuo/iuo"

CmdFinderBase& CmdFinderBase::operator=(CmdFinderBase const &&tmp)
{
    static bool called = false;
    deprecated__(called, 
        "CmdFinderBase::operator=(CommandFinderBase const &&tmp) is "
        "deprecated. Please recompile this program");

    fswap(*this, const_cast<CmdFinderBase &>(tmp));
    return *this;
}
