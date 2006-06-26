#include "cmdfinderbase.ih"

bool CmdFinderBase::matchUniqueInsensitive(std::string const &key) const
{
    return 
        d_cmd.length()
        &&
        String(key).lc().find(String(d_cmd).lc()) != string::npos;
}
