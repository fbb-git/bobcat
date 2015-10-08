#include "configfile.ih"

ConfigFile::const_RE_iterator ConfigFile::beginRE(string const &re)
{
    static bool called = false;
    deprecated__(called, "ConfigFile::beginRE(std::string const &)");

    return d_ptr->beginRE(re);
}

