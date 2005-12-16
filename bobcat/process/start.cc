#include "process.ih"


void Process::start(iomode mode, Program program)
{
    clear();

    d_childCout.clear();
    d_childCerr.clear();
    d_childCin.clear();

    d_ret = -1;
    setPipes(mode);

    d_processType = program;

    fork();
}
