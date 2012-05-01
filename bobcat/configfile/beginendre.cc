#include "configfile.ih"

pair<ConfigFile::const_RE_iterator, ConfigFile::const_RE_iterator>
    ConfigFile::beginEndRE(std::string const &re)
{
    auto begin = d_ptr->beginRE(re);

    pair<const_RE_iterator, const_RE_iterator> ret(begin, d_ptr->endRE());

    return ret;
}
