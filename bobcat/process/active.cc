#include "process.ih"

bool Process::active()
{
    if (d_child.pid != 0)
    {
        int retChild = waitpid(d_child.pid, &d_child.ret, WNOHANG);

        if (retChild == d_child.pid)
            d_child.pid = 0;               // process has ended
    }
        
    return d_child.pid;
}






