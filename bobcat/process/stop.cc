#include "process.ih"

int Process::stop()
{
    if (!getPid())                  // pid = 0 occurs when a Process 
        return 0;                   // object was created, but did not yet
                                    // fork(), and its program terminates.
                                    // This may happen, e.g., in a daemon.
    d_command.clear();

    d_child_inp.reset(0);

    if (pid_t pid = getPid())
        kill(pid, SIGTERM);

    if (pid_t pid = getPid())
        kill(pid, SIGTERM);

    if (pid_t pid = getPid())
        kill(pid, SIGKILL);

    d_child_outp.reset(0);
    d_child_errp.reset(0);

    return d_ret = waitForChild();
}

