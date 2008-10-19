#include "process.ih"

Process &Process::operator()(size_t waitSeconds, iomode mode)
{
    setWait(waitSeconds);
    setIOMode(mode);
    return *this;
}
