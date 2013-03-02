#include "configfile.ih"

vector<string>::const_iterator ConfigFile::find(string const &target) const
{
    return find_if(begin(), end(), FnWrap::unary(
        d_caseSensitive ? finder : casefinder, target));
}
