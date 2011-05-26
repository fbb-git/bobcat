#include "arg.ih"

size_t Arg::option(size_t *idx, string *value, char const *longOpt) const
{
    SSVMapIterator it = d_longOptv.find(longOpt);
    if (it == d_longOptv.end())
        return 0;

    return firstNonEmpty(idx, value, it->second);
}
