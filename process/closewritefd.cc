#include "process.ih"

void Process::closeWriteFd(Pipe &pipe)
{
    close(pipe.writeFd());
}

