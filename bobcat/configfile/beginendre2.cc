#include "configfile.ih"

pair<ConfigFile::const_RE_iterator, ConfigFile::const_RE_iterator>
    ConfigFile::beginEndRE()
{
    return 
        pair<const_RE_iterator, const_RE_iterator>(d_ptr->endRE(),
                                                   d_ptr->endRE());
}
