#include "configfile.ih"

size_t ConfigFile__::index(const_iterator const &iterator)
{
    return d_index[iterator - begin()];
}

size_t ConfigFile::index(const_iterator const &iterator)
{
    return d_ptr->index(iterator);
}

