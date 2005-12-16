#include "process.ih"

int Process::stop()
{
    d_command.clear();

    d_child_inp.reset(0);

    if (pid_t pid = getPid())
        kill(pid, SIGTERM) && kill(pid, SIGKILL);

    d_child_outp.reset(0);
    d_child_errp.reset(0);

    return d_ret = waitForChild();
}
