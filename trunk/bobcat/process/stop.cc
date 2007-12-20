#include "process.ih"

int Process::stop()
{
    if (!pid())                     // pid = 0 occurs when a Process 
        return 0;                   // object was created, but did not yet
                                    // fork(), and its program terminates.
                                    // This may happen, e.g., in a daemon.

    if (d_child_inp.get())
    {
        ::close(d_child_inp->writeFd());
        d_child_inp.reset(0);
    }

    if (d_child_outp.get())
    {
        ::close(d_child_outp->readFd());
        d_child_outp.reset(0);
    }

    if (d_child_errp.get())
    {
        ::close(d_child_errp->readFd());
        d_child_errp.reset(0);
    }

    d_selector.setAlarm(d_waitSeconds);
    try
    {
        d_selector.wait();
    }
    catch(...)
    {}

    d_command.clear();

    if (pid_t p = pid())
        kill(p, SIGTERM);

    if (pid_t p = pid())
        kill(p, SIGTERM);

    if (pid_t p = pid())
        kill(p, SIGKILL);

    return d_ret = waitForChild();
}







