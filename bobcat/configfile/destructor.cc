#include "configfile.hh"

ConfigFile::~ConfigFile()
{
    delete d_ptr;
}
