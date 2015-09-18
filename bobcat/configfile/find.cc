#include "configfile.hh"

vector<string>::const_iterator ConfigFile__::find(string const &target) const
{
    return find_if(
                begin(), end(), 
                [&](string const &haystack)
                {
                    return (d_caseSensitive ? finder : casefinder)
                                (haystack, target);
                }
            );
}

vector<string>::const_iterator ConfigFile::find(string const &target) const
{
    return d_ptr->find(target);
}
