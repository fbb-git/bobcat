#include "cmdfinderbase.ih"

CmdFinderBase::CmdFinderBase(CmdFinderBase const &&tmp) 
:
    d_cmd(move(tmp.d_cmd)),
    d_beyond(move(tmp.d_beyond))
{}
