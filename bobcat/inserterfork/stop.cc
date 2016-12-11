#include "inserterfork.ih"

int InserterFork::stop()
{
    flush();
    close();

    return waitForChild();
}
