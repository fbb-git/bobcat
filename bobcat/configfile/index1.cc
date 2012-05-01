#include "configfile.ih"

size_t ConfigFile__::index(size_t lineNr)
{
    return d_index[lineNr];
}

size_t ConfigFile::index(size_t lineNr)
{
    return d_ptr->index(lineNr);
}

