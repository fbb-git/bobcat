#include "configfile.ih"

ConfigFile::ConfigFile(ConfigFile const &rhs)
:
    d_ptr(new ConfigFile__(*rhs.d_ptr))
{}
