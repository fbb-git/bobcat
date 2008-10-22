#include "process.ih"

#include <iostream>

void Process::forking()
{
    fork();

    // this is the parent, following parentRedirections()
    
    d_child.pid = pid();

std::cerr << "FORKED CHILD " << pid() << endl;


//
//    if (d_waitSeconds == 0)
//    {
//        d_waiter.pid = 0;
//        return;
//    }

//    d_waiter.pid = ::fork();
//
//    if (d_waiter.pid < 0)
//    {
//        d_waiter.pid = 0;
//        stop();
//        throw Errno("Process ") << insertable << d_command << 
//                    ": can't start timeout monitor" << throwable;
//    }
//    else if (d_waiter.pid == 0)
//    {
//        d_childCinbuf.open(0);     // Close inherited pipes
//        d_childCoutbuf.open(0);
//        d_childCerrbuf.open(0);
//
//        ::close(STDIN_FILENO);
//        ::close(STDOUT_FILENO);
//        ::close(STDERR_FILENO);
//
//        sleep(d_waitSeconds);
//
//        throw TIMEOUT;
//    }
}






