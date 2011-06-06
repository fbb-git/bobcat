#include "configfile.ih"

#include "../iuo/iuo"

ConfigFile &ConfigFile::operator=(ConfigFile const &&tmp)
{
    static bool called = false;
    deprecated__(called, "ConfigFile::operator=(ConfigFile const &&tmp)");
    fswap(*this, const_cast<ConfigFile &>(tmp));
    return *this;
}
