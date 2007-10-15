#include "log.ih"

Log::Log(char const *delim)
:
    LogBuffer(TIMESTAMPS, false, delim),
    ostream(this)
{
    init();
}
