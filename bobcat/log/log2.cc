#include "log.ih"

Log::Log(ostream &out, StaticType type, char const *delim)
:
    LogBuffer(out, TIMESTAMPS, true, delim),
    ostream(this)
{
    init(type);
}
