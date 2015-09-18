#include "log.hh"

Log &Log::instance()
{
    if (!s_stream.get())
        throw Exception() << "Log::getInstance(): FBB::Log not initialized";

    return *s_stream.get();
}
