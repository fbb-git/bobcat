#include "configfile.ih"

ConfigFile__::const_RE_iterator ConfigFile__::beginRE(string const &re)
{
    if (re != d_re)
        resetVsIter(re);

    return RE_iterator(d_vsIter, 0);
}
