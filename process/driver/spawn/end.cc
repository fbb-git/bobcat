#include "spawn.hh"

void Spawn::end()
{
    flush();

    ::close(d_insertPipe.writeFd());

    waitForChild();
}
