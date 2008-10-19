#include "process.ih"


void Process::start(size_t waitSeconds, iomode mode, Program program)
{
    if (d_command.empty())
        return;

    stop();

    open(d_childCout, d_childCin);  // associate in/out streams

    d_waitSeconds = waitSeconds;

    clear();                        // clear the IO stream

    d_childCout.clear();
    d_childCerr.clear();
    d_childCin.clear();

    setPipes(mode);

    d_processType = program;

    forking();
}


