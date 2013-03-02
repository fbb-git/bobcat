#include "arg.ih"

unsigned Arg::option(unsigned idx, string *value, int optChar) const
{
    ISVMapIterator it = d_optv.find(optChar);
    if (it == d_optv.end())
        return 0;

    unsigned ret = it->second.size();   // size of the value-vector

    if (idx < ret && value)             // if the idx is within range and
        *value = it->second[idx];       // value requested, return it.
    
    return ret;                         // return this option count.
}
