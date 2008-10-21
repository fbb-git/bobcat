#include "process.ih"

void Process::start(size_t waitSeconds, iomode mode, Program program)
{
    if (d_active)
        stop();

    d_active = true;

    d_waitSeconds = waitSeconds;

    d_childCin.clear();
    d_childCout.clear();
    d_childCerr.clear();

    clear();                        // clear the IO stream

    d_processType = program;

    setPipes(mode);

    forking();
}
