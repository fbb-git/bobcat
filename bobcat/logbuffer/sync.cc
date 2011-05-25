#include "logbuf.ih"

int LogBuffer::sync()
{
    return pSync();
}
