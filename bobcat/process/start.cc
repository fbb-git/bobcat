#include "process.ih"

void Process::start(IOMode mode, ProcessType type, size_t timeLimit)
{
    start(bufSize(), mode, type, timeLimit);
}
