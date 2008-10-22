#include "process.ih"

pid_t Process::discontinue(RetPid &proc)
{
//    if (proc.pid > 0)
//    {
////std::cerr << "Discontinue " << proc.pid << endl;

        kill(proc.pid, SIGHUP) && kill(proc.pid, SIGHUP) && 
                                                    kill(proc.pid, SIGTERM);
        proc.pid = waitpid(proc.pid, &proc.ret, 0);
//    }

    return proc.pid = 0;
}
