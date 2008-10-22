#include "process.ih"

Process &Process::operator()(iomode mode, ProcessType type, size_t timeLimit)
{
    d_timeLimit = timeLimit;
    d_processType = type;
    sanitizeIOMode(mode);

    return *this;
}
