#include "process.hh"

void Process::closeReadFd(Pipe &pipe)
{
    close(pipe.readFd());
}

