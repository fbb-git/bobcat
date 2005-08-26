#include "process.ih"

int Process::system()
{
    d_processType = SYSTEM;

    d_out = new Pipe;
    d_err = new Pipe;

    fork();

    delete d_out;
    delete d_err;

    return d_ret;
}
