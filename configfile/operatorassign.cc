#include "configfile.ih"

ConfigFile &ConfigFile::operator=(ConfigFile &&tmp)
{
    *d_ptr = move(*tmp.d_ptr);
    return *this;
}

