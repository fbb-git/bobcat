#include "configfile.ih"

ConfigFile__::const_RE_iterator ConfigFile__::endRE() const
{
    return RE_iterator(d_vsIter, d_vsIter.size());
}


