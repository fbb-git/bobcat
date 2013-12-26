#include "process.ih"

Process &Process::operator()(size_t bufSize, IOMode mode, ProcessType type,
size_t timeLimit) 
{
    d_data->d_bufSize = bufSize;
    d_timeLimit = timeLimit;
    d_processType = type;
    sanitizeIOMode(mode);

    return *this;
}
