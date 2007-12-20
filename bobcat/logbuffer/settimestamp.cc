#include "logbuffer.ih"

void LogBuffer::settimestamp(TimeStamps timestamps, char const *delim)
{
    if ((d_insertTimestamp = (timestamps == TIMESTAMPS)))
        d_delim = !delim ? "" : delim;
}
