#include "logbuffer.hh"

void LogBuffer::settimestamp(TimeStamps timestamps, char const *delim)
{
    if ( (d_timestamps = timestamps) != NOTIMESTAMPS)
        d_delim = !delim ? "" : delim;
}
