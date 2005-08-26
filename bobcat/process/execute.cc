#include "process.ih"

int Process::execute(PathType pathType, Program program)
{
    if (program == USE_SHELL)
        return system();

    d_processType = pathType == USE_PATH ? EXECVP : EXECV;

    d_out = new Pipe;
    d_err = new Pipe;

    fork();

    delete d_out;
    delete d_err;

    return d_ret;
}
