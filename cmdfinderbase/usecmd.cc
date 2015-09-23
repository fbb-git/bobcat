#include "cmdfinderbase.hh"

void CmdFinderBase::useCmd(std::string const &cmd)
{
    d_beyond.erase();
    d_cmd = cmd;
}
