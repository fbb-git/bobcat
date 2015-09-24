#include "configfile.ih"

ConfigFile::~ConfigFile()
{
    delete d_ptr;
}
