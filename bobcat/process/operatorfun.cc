#include "process.ih"

Process &Process::operator()(iomode mode, ProcessType type, size_t waitSeconds)
{
    d_waitSeconds = waitSeconds;
    d_processType = type;
    sanitizeIOMode(mode);

    return *this;
}
