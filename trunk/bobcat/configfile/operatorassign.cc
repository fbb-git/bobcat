#include "configfile.ih"

ConfigFile &ConfigFile::operator=(ConfigFile &&tmp)
{
    fswap(*this, tmp);
    return *this;
}
