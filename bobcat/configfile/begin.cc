#include "configfile.ih"

ConfigFile__::const_iterator ConfigFile__::begin() const
{
    return d_line.begin();
}
   
ConfigFile::const_iterator ConfigFile::begin() const
{
    return d_ptr->begin();
}
   
