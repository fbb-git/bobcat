#include "process.ih"

int Process::stop()
{
    if (!d_active)
        return -1;

    d_command.clear();

    discontinue(d_child);
    discontinue(d_monitor);

    d_active = false;

    return d_child.ret;
}







