#include "main.ih"

void finalization()
{
    cout << "USed pipes " << p1 << ", " << p2 << endl;

    kill(pid, SIGTERM);
    cout << "Wait returns " << wait(0) << ", child pid = " << pid << endl;
}
