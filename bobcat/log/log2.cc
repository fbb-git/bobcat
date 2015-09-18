#include "log.hh"

Log::Log(ostream &out, char const *delim)
:
    LogBuffer(out, TIMESTAMPS, true, delim),
    ostream(this)
{
    init();
}
