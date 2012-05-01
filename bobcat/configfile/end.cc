#include "configfile.ih"

ConfigFile__::const_iterator ConfigFile__::end() const
{
    return d_line.end();
}
   
ConfigFile::const_iterator ConfigFile::end() const
{
    return d_ptr->end();
}
   
