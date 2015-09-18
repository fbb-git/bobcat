#include "process.hh"

void Process::closeWriteFd(Pipe &pipe)
{
    close(pipe.writeFd());
}

