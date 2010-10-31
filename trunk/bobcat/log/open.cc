#include "log.ih"

void Log::open(string const &filename, ios::openmode mode, char const *delim)
{
    if (!filename.length() || filename == "&1")
        setStream(cout);
    else if (filename == "&2")
        setStream(cerr);
    else
    {
        d_stream.open(filename.c_str(), mode);
        if (!d_stream)
            Errno("Log::Log(string, ...)") << insertable <<
                ": can't write `" << filename << "'" << throwable;
        setStream(d_stream);
    }
    settimestamp(TIMESTAMPS, delim);
    init();
}
