#include "configfile.ih"

size_t ConfigFile__::size() const
{
    return d_line.size();
}

size_t ConfigFile::size() const
{
    return d_ptr->size();
}
