#include "configfile.ih"

vector<string>::const_iterator ConfigFile::find(string const &target) const
{
    return find_if(
                begin(), end(), 
                [&, d_caseSensitive](string const &haystack)
                {
                    return (d_caseSensitive ? finder : casefinder)
                                (haystack, target);
                }
            );
}
