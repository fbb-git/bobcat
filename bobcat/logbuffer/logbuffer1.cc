#include "logbuffer.ih"

LogBuffer::LogBuffer(TimeStamps timestamps,
                    bool active, char const *delim)
:
    d_stream(&cerr),
    d_active(active),
    d_empty(true)
{
    settimestamp(timestamps, delim);
    setp(0, 0);     // we're not using buffering, so we see every single
                    // character. overflow() may therefore act like a filter,
                    // which decides what to do depending on the booleans.
                    // see overflow() for details.
}
