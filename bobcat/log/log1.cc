#include "log.hh"

Log::Log()
:
    LogBuffer(TIMESTAMPS, false, " "),
    ostream(this)
{
    init();
}
