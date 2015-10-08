#include "log.ih"

Log::Log()
:
    LogBuffer(TIMESTAMPS, false, " "),
    ostream(this)
{
    init();
}
