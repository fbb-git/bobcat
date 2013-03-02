#include "arg.ih"

unsigned Arg::option(int optChar) const
{
    ISVMapIterator it = d_optv.find(optChar);
    return it == d_optv.end() ? 0 : it->second.size();
}
