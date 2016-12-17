#include "cininserter.ih"

int CinInserter::stop()
{
    if (d_stopped)
        return ret();

    flush();
    close();

    return setRet(waitForChild());
}
