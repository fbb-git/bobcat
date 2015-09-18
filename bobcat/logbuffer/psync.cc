#include "logbuffer.hh"

int LogBuffer::pSync()
{
    d_stream->flush();
    return 0;
}
