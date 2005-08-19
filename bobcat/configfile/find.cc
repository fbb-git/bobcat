#include "configfile.ih"

vector<string>::const_iterator ConfigFile::find(string const &target) const
{
    return d_caseSensitive ?
        std::find(begin(), end(), target)
    :
        findRE(target);
}
