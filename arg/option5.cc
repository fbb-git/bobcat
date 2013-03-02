#include "arg.ih"

unsigned Arg::option(unsigned idx, 
                 string *value, char const *longOption) const
{
    SSVMapIterator it = d_longOptv.find(longOption);
    if (it == d_longOptv.end())
        return 0;

    unsigned ret = it->second.size();   // size of the value-vector

    if (idx < ret && value)             // if the idx is within range and
        *value = it->second[idx];       // value requested, return it.
    
    return ret;                         // return this option count.
}
