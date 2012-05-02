#include "log.ih"

Log &Log::instance()
{
    if (!s_stream.get())
        throw Errno("Log::getInstance()") <<  ": FBB::Log not initialized";

    return *s_stream.get();
}
