#include "process.hh"

Process &Process::operator()(size_t mode, ProcessType type, size_t timeLimit)
{
    return operator()(iomode(mode), type, timeLimit, bufSize());
}
