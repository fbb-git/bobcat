#include "logbuffer.ih"

void LogBuffer::insertTimestamp()
{
    time_t curtime = time(0);
    struct tm *loctime = localtime (&curtime);
    char buffer[256];       // see time functions example of `info libc'

    strftime(buffer, 256, "%b %e %T", loctime);
    *d_stream << buffer << d_delim;
}
