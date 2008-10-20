#include "process.ih"

#include <iostream>

void Process::forking()
{
    fork();
    
    d_child.pid = pid();

//std::cerr << "FORKING CHILD " << d_child.pid << endl;

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
        close(d_child_inp,  &Pipe::writeFd);  // close pipes inherited from
        close(d_child_outp, &Pipe::readFd);   // the parent
        close(d_child_errp, &Pipe::readFd);

        ::close(STDIN_FILENO);
        ::close(STDOUT_FILENO);
        ::close(STDERR_FILENO);

        sleep(d_waitSeconds);

        throw TIMEOUT;
    }
}






