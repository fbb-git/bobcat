#include "cmdfinderbase.ih"

#include "../iuo/iuo"

CmdFinderBase::CmdFinderBase(CmdFinderBase const &&tmp) 
:
    d_cmd(move(tmp.d_cmd)),
    d_beyond(move(tmp.d_beyond))
{
    static bool called = false;
    deprecated__(called, 
        "CmdFinderBase::CmdFinderBase(CmdFinderBase const &&tmp) is "
        "deprecated. Please recompile this program");
}
