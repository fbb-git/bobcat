#include "process.ih"

bool Process::active()
{
    if (d_monitor.pid != 0)
    {
        int retWaiter = waitpid(d_monitor.pid, &d_monitor.ret, WNOHANG);

        if (retWaiter == d_monitor.pid)
        {
            d_monitor.pid = 0;               // process has ended
            discontinue(d_child);
        }
    }
    else if (d_child.pid != 0)
    {
        int retChild = waitpid(d_child.pid, &d_child.ret, WNOHANG);

        if (retChild == d_child.pid)
        {
            d_child.pid = 0;               // process has ended
            discontinue(d_monitor);
        }
    }
        
    return d_child.pid;
}






