#include "log.ih"

Log &Log::initialize(std::string const &filename, 
                    std::ios::openmode mode, char const *delim)
{
    if (s_stream.get())
        throw Errno("Log::getInstance()") << insertable <<
            ": FBB::Log already initialized" << throwable;

    s_stream.reset(new Log(filename, mode, delim));
    return *s_stream.get();
}
