#include "cmdfinderbase.ih"

void CmdFinderBase::swap(CmdFinderBase &rhs) 
{
    d_cmd.swap(rhs.d_cmd);
    d_beyond.swap(rhs.d_beyond);
}
