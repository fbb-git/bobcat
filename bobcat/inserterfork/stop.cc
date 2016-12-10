#include "inserterfork.ih"

int InserterFork::stop()
{
    d_oChildIn.flush();
    d_oChildInbuf.close();

    return waitForChild();
}
