#include "configfile.ih"

#include "../iuo/iuo"

ConfigFile &ConfigFile::operator=(ConfigFile const &&tmp)
{
    static bool called = false;
    deprecated__(called, "ConfigFile::operator=(ConfigFile const &&tmp) is "
                        "deprecated. Please recompile this program");
    fswap(*this, const_cast<ConfigFile &>(tmp));
    return *this;
}
