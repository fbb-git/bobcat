#include "log.hh"

Log::Log(string const &filename, ios::openmode mode,
        char const *delim)
:
    ostream(this)
{
    open(filename, mode, delim);
}
