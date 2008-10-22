#include "process.ih"

Process &Process::operator()(size_t waitSeconds, iomode mode, ProcessType type)
{
    setWait(waitSeconds);
    setIOMode(mode);
    setProcessType(type);

    return *this;
}
