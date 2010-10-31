#include "configfile.ih"

vector<string>::const_iterator ConfigFile::findRE(string const &re) const
{
    Pattern pattern(re, d_caseSensitive);

    return find_if(begin(), end(), FnWrap::unary(&match, pattern));
}

