#include "configfile.hh"

void ConfigFile__::resetVsIter(string const &re)
{
    d_vsIter.clear();

    d_re = re;
    
    d_pattern.setPattern(re, d_caseSensitive);

    for(auto start = begin(), stop = end(); start != stop; ++start)
    {
        if (d_pattern << *start)
            d_vsIter.push_back(start);
    }
}
