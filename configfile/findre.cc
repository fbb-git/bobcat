#include "configfile.hh"

vector<string>::const_iterator ConfigFile__::findRE(string const &re) const
{
    d_pattern.setPattern(re, d_caseSensitive);

    return find_if(
                begin(), end(), 
                [&](string const &str)
                {
                    return d_pattern << str;  
                }
            );
}

vector<string>::const_iterator ConfigFile::findRE(string const &re) const
{
    return d_ptr->findRE(re);
}
