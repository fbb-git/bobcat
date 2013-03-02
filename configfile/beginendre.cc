#include "configfile.ih"

pair<ConfigFile::const_RE_iterator, ConfigFile::const_RE_iterator>
    ConfigFile::beginEndRE(std::string const &re)
{
    const_RE_iterator begin = beginRE(re);

    pair<const_RE_iterator, const_RE_iterator> ret(begin, endRE());

    return ret;
}
