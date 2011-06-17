#include "cmdfinderbase.ih"

CmdFinderBase::CmdFinderBase(CmdFinderBase &&tmp) 
:
    d_cmd(move(tmp.d_cmd)),
    d_beyond(move(tmp.d_beyond))
{}
