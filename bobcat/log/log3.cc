#include "log.ih"

Log::Log(string const &filename, ios::openmode mode,
        char const *delim)
:
    ostream(this)
{
    open(filename, mode, delim);
}
