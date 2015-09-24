#include "process.ih"

Process &Process::operator()(IOMode mode, ProcessType type, size_t timeLimit,
                             size_t bufSize) 
{
    d_data->d_bufSize = bufSize;
    d_timeLimit = timeLimit;
    d_processType = type;
    sanitizeIOMode(mode);

    return *this;
}
