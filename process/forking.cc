#include "process.ih"

#include <iostream>

void Process::forking()
{
    fork();

    // this is the parent, following parentRedirections()
    
    d_child.pid = pid();

    if (d_timeLimit == 0)         // no wait, set monitor.pid to 0: no 
    {                               // time monitoring
        d_monitor.pid = 0;
        return;
    }

    d_monitor.pid = ::fork();

    if (d_monitor.pid < 0)          // monitor process fails
    {
        d_monitor.pid = 0;
        stop();
        throw Errno("Process ") << d_command << 
                                        ": can't start the timeout monitor";
    }
    else if (d_monitor.pid == 0)    // actual monitoring process
    {
                                    // close open pipes inherited from the
                                    // parent process
        closeWriteFd(d_oChildInPipe);
        closeReadFd(d_iChildOutPipe);
        closeReadFd(d_iChildErrPipe);

        sleep(d_timeLimit);         // end the child after 'timeLimit'
        exit(0);
    }
}
