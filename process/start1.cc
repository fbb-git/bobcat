#include "process.hh"

void Process::start(size_t mode, ProcessType type, size_t timeLimit)
{
    start(iomode(mode), type, timeLimit, bufSize());
}
