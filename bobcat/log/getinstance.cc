#include "log.ih"

Log &Log::getInstance()
{
    if (!s_stream.get())
        throw Errno("Log::getInstance()") << insertable <<
            ": FBB::Log not initialized" << throwable;

    return *s_stream.get();
}
