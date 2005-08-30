#include "log.ih"

Log::Log(string const &filename, StaticType type, ios::openmode mode,
        char const *delim)
:
    ostream(this)
{
    if (!filename.length())
        setStream(cout);
    else
    {
        d_stream.open(filename.c_str(), mode);
        if (!d_stream)
            Errno("Log::Log(string, ...)") << insertable <<
                ": `" << filename << "' cannot be opened to write" << 
                throwable;
        setStream(d_stream);
    }
    settimestamp(TIMESTAMPS, delim);
    init(type);
}
