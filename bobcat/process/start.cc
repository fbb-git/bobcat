#include "process.ih"


void Process::start(size_t waitSeconds, iomode mode, Program program)
{
    if (d_command.empty())
        return;

    d_waitSeconds = waitSeconds;

    clear();

    d_childCout.clear();
    d_childCerr.clear();
    d_childCin.clear();

    d_ret = -1;
    setPipes(mode);

    d_processType = program;

    fork();
}
