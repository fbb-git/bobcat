#include "log.hh"

Log &Log::instance()
{
    if (!s_stream.get())
        throw Exception() << "Log::instance: FBB::Log not initialized";

    return *s_stream.get();
}
