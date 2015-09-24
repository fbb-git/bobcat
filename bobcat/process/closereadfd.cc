#include "process.ih"

void Process::closeReadFd(Pipe &pipe)
{
    close(pipe.readFd());
}

