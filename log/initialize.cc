#include "log.ih"

Log &Log::initialize(std::string const &filename, 
                    std::ios::openmode mode, char const *delim)
{
    if (s_stream.get())
        throw Errno("Log::getInstance()") << ": FBB::Log already initialized";

    s_stream.reset(new Log(filename, mode, delim));
    return *s_stream.get();
}
