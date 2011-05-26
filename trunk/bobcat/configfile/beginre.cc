#include "configfile.ih"

ConfigFile::const_RE_iterator ConfigFile::beginRE(string const &re)
{
    if (re != d_re)
        resetVsIter(re);

    return RE_iterator(d_vsIter, 0);
}
