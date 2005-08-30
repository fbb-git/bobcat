#include "log.ih"

Log &Log::getInstance()
{
    if (!s_stream)
        throw Errno("Log::getInstance()") << insertable <<
            ": no FBB::Log object available" << throwable;

    return *s_stream;
}
