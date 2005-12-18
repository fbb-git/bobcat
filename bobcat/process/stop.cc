#include "process.ih"

#include <iostream>

int Process::stop()
{
    if (!pid())                     // pid = 0 occurs when a Process 
        return 0;                   // object was created, but did not yet
                                    // fork(), and its program terminates.
                                    // This may happen, e.g., in a daemon.

    ::close(d_child_inp->writeFd());
    d_child_inp.reset(0);

    ::close(d_child_outp->readFd());
    d_child_outp.reset(0);

    ::close(d_child_errp->readFd());
    d_child_errp.reset(0);

    d_command.clear();

    if (pid_t p = pid())
        kill(p, SIGTERM);

    if (pid_t p = pid())
        kill(p, SIGTERM);

    if (pid_t p = pid())
        kill(p, SIGKILL);

    return d_ret = waitForChild();
}







