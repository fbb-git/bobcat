#include "process.ih"

void Process::start(size_t waitSeconds, iomode mode, Program program)
{
    if (d_active)
        stop();

    d_active = true;

    d_waitSeconds = waitSeconds;

    setPipes(mode);

    d_childCout.clear();
    d_childCerr.clear();
    d_childCin.clear();

    clear();                        // clear the IO stream
    open(d_childCout, d_childCin);  // associate in/out streams

    d_processType = program;

    forking();
}






