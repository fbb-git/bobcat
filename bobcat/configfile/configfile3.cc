#include "configfile.ih"

ConfigFile::ConfigFile(ConfigFile &&tmp)
:
    d_ptr( new ConfigFile__(move(*tmp.d_ptr) ))
{}
