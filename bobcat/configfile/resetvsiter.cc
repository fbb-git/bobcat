#include "configfile.ih"

void ConfigFile::resetVsIter(string const &re)
{
    d_vsIter.clear();

    d_re = re;
    
    Pattern pattern(re, d_caseSensitive);

    for(auto start = begin(), stop = end(); start != stop; ++start)
    {
        if (pattern << *start)
            d_vsIter.push_back(start);
    }
}
