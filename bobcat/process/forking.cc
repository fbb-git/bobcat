#include "process.ih"

void Process::forking()
{
    if (d_mode == IOMode::DIRECT)
        childProcess();

    fork();

    // this is the parent, following parentRedirections()
    
    d_child.pid = pid();

    if (d_timeLimit == 0)       // no wait, no monitoring
        return;

//  Timeout monitoring now done by threading.

//    pid_t pid = ::fork();
//
//    if (pid < 0)                // forking fails
//    {
//        stop();
//        throw Exception() << "Process " << d_command << 
//                                        ": can't start the timeout monitor";
//    }
//    else if (d_monitor.pid == 0)    // actual monitoring process
//    {
//                                    // close open pipes inherited from the
//                                    // parent process
//        closeWriteFd(d_oChildInPipe);
//        closeReadFd(d_iChildOutPipe);
//        closeReadFd(d_iChildErrPipe);
//
//        sleep(d_timeLimit);         // end the child after 'timeLimit'
//        exit(0);
//    }
}
