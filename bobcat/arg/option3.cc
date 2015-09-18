#include "arg.hh"

size_t Arg__::option(size_t idx, string *value, int optChar) const
{
    ISVMapIterator it = d_optv.find(optChar);
    if (it == d_optv.end())
        return 0;

    size_t ret = it->second.size();   // size of the value-vector

    if (idx < ret && value)             // if the idx is within range and
        *value = it->second[idx];       // value requested, return it.
    
    return ret;                         // return this option count.
}

size_t Arg::option(size_t idx, string *value, int optChar) const
{
    return d_ptr->option(idx, value, optChar);
}
