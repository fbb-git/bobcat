#include "configfile.hh"

ConfigFile &ConfigFile::operator=(ConfigFile const &rhs)
{
    ConfigFile tmp(rhs);
    swap(d_ptr, tmp.d_ptr);
    return *this;
}

    
