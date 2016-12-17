#include "cininserter.ih"

int CinInserter::stop()
{
    if (d_stopped)
        return -1;

    flush();
    close();

    return waitForChild();
//    return setRet(waitForChild());
}
