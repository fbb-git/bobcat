#include "process.hh"

void Process::setBufSize(size_t bufSize)
{
    d_data->d_bufSize =   bufSize == 0 ? 1 : bufSize;
}
