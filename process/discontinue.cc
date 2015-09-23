#include "process.hh"

pid_t Process::discontinue(RetPid &proc)
{
    if (proc.pid > 0)
    {
        kill(proc.pid, SIGHUP) && kill(proc.pid, SIGHUP) && 
                                                    kill(proc.pid, SIGTERM);
        proc.pid = waitpid(proc.pid, &proc.ret, 0);
    }

    return proc.pid = 0;
}
