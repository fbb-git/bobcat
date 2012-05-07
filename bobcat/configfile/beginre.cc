#include "configfile.ih"

ConfigFile__::const_RE_iterator ConfigFile__::beginRE(string const &re)
{
    if (re != d_re)
        resetVsIter(re);

    return RE_iterator(d_vsIter, 0);
}

ConfigFile::const_RE_iterator ConfigFile::beginRE(string const &re)
{
    static bool called = false;
    deprecated__(called, "ConfigFile::beginRE(std::string const &)");

    return d_ptr->beginRE(re);
}

