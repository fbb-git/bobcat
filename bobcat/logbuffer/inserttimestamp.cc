#include "logbuffer.ih"

void LogBuffer::insertTimestamp()
{
    time_t curtime = time(0);
    struct tm *timestruct = 
        (d_timestamps == TIMESTAMPS ? localtime : gmtime)(&curtime);

    char buffer[256];       // see time functions example of `info libc'

    strftime(buffer, 256, "%b %e %T", timestruct);
    *d_stream << buffer << d_delim;
}
