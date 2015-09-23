#include "process.hh"

void Process::newPipe(Pipe &pipe)
{
    closeReadFd(pipe);
    closeWriteFd(pipe);

    pipe = Pipe();
}
