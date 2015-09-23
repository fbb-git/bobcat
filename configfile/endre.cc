#include "configfile.hh"

ConfigFile::const_RE_iterator ConfigFile::endRE() const
{
    static bool called = false;
    deprecated__(called, "ConfigFile::endRE()");

    return d_ptr->endRE();
}

