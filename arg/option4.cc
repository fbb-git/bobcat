#include "arg.ih"

unsigned Arg::option(unsigned *idx, string *value, int optChar) const
{
    ISVMapIterator it = d_optv.find(optChar);
    if (it == d_optv.end())
        return 0;

    return firstNonEmpty(idx, value, it->second);
}
