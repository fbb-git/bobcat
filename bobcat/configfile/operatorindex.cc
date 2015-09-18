#include "configfile.hh"

std::string const &ConfigFile::operator[](size_t idx) const
{
    return (*d_ptr)[idx];
}
