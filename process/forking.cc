#include "process.hh"

void Process::forking()
{
    newPipes();

    if (d_mode == IOMode::DIRECT)
        childProcess();

    fork();
}
