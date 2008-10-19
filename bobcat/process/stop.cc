#include "process.ih"

int Process::stop()
{
    if (!d_active)
        return -1;

    d_active = false;

    if (!verify())                  // No running child process
        return d_child.ret;

    discontinue(d_child);
    verify();

    close(d_child_inp);
    close(d_child_outp);
    close(d_child_errp);

    d_command.clear();

    return d_child.ret;
}







