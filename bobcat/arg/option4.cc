#include "arg.ih"

size_t Arg__::option(size_t *idx, string *value, int optChar) const
{
    ISVMapIterator it = d_optv.find(optChar);
    if (it == d_optv.end())
        return 0;

    return firstNonEmpty(idx, value, it->second);
}

size_t Arg::option(size_t *idx, string *value, int optChar) const
{
    return d_arg->option(idx, value, optChar);
}

