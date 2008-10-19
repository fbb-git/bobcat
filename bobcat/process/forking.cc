#include "process.ih"

void Process::forking()
{
    d_active = true;

    fork();
    
    d_child.pid = pid();

    if (d_waitSeconds == 0)
    {
        d_waiter.pid = 0;
        return;
    }

    d_waiter.pid = ::fork();

    if (d_waiter.pid < 0)
    {
        d_waiter.pid = 0;
        stop();
        throw Errno("Process ") << insertable << d_command << 
                    ": can't start timeout monitor" << throwable;
    }
    else if (d_waiter.pid == 0)
    {
        close(d_child_inp);
        close(d_child_outp);
        close(d_child_errp);

        ::close(STDIN_FILENO);
        ::close(STDOUT_FILENO);
        ::close(STDERR_FILENO);

        sleep(d_waitSeconds);

        throw TIMEOUT;
    }
}






