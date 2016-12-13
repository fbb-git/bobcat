#include "cininserter.ih"

int CinInserter::stop()
{
    flush();
    close();

    return waitForChild();
}
