#include <iostream>

#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>

using namespace std;

pid_t discontinue(pid_t procId)
{
    if (procId == 0)
        return 0;

    int ret;

    if ((ret = kill(procId, SIGHUP)) && (ret = kill(procId, SIGHUP)))
        ret = kill(procId, SIGKILL);

    cout << "Process " << procId << " killed with return value " << ret << 
                                                                    endl;
    if (!ret)
        wait(0);    

    return 0;
}
