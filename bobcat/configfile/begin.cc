#include "configfile.ih"

ConfigFile::const_iterator ConfigFile::begin() const
{
    return d_ptr->begin();
}
   
