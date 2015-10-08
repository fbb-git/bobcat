#include "cmdfinderbase.ih"

bool CmdFinderBase::matchUniqueInsensitive(std::string const &key) const
{
    return 
        d_cmd.length()
        &&
        String::lc(key).find(String::lc(d_cmd)) != string::npos;
}
