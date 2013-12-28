#include "spawn.ih"

void Spawn::end()
{
    flush();

    ::close(d_insertPipe.writeFd());

    waitForChild();
}
