#include "configfile.hh"

ConfigFile::const_iterator ConfigFile::end() const
{
    return d_ptr->end();
}
   
