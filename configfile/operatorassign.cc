#include "configfile.ih"

ConfigFile &ConfigFile::operator=(ConfigFile const &&tmp)
{
    fswap(*this, const_cast<ConfigFile &>(tmp));
    return *this;
}
