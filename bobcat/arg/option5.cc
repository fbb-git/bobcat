#include "arg.ih"

size_t Arg__::option(size_t idx, 
                 string *value, char const *longOption) const
{
    SSVMapIterator it = d_longOptv.find(longOption);
    if (it == d_longOptv.end())
        return 0;

    size_t ret = it->second.size();   // size of the value-vector

    if (idx < ret && value)             // if the idx is within range and
        *value = it->second[idx];       // value requested, return it.
    
    return ret;                         // return this option count.
}

size_t Arg::option(size_t idx, 
                 string *value, char const *longOption) const
{
    return d_arg->option(idx, value, longOption);
}
