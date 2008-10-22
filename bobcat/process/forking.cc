#include "process.ih"

#include <iostream>

void Process::forking()
{
    fork();

    // this is the parent, following parentRedirections()
    
    d_child.pid = pid();

//std::cerr << "FORKED CHILD " << pid() << endl;

    if (d_waitSeconds == 0)         // no wait, set monitor.pid to 0: no 
    {                               // time monitoring
        d_monitor.pid = 0;
        return;
    }

    d_monitor.pid = ::fork();

    if (d_monitor.pid < 0)          // monitor process fails
    {
        d_monitor.pid = 0;
        stop();
        throw Errno("Process ") << insertable << d_command << 
                    ": can't start the timeout monitor" << throwable;
    }
    else if (d_monitor.pid == 0)    // actual monitoring process
    {
                                    // close open pipes inherited from the
                                    // parent process
//        if (d_mode & CIN)           
//            ::close(d_child_inp->writeOnly());
//        if (d_mode & (COUT | MERGE_COUT_CERR))
//            ::close(d_child_outp->readOnly());
//        if (d_mode & CERR)
//            ::close(d_child_errp->readOnly());

        sleep(d_waitSeconds);

        throw TIMEOUT;              // NOTE: PROCESS SHOULD CATCH THE TIMEOUT
    }
}






