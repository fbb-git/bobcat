#include "log.ih"

Log::Log(StaticType type, char const *delim)
:
    LogBuffer(cout, TIMESTAMPS, true, delim),
    ostream(this)
{
    init(type);
}
