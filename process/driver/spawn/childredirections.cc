#include "spawn.hh"

void Spawn::childRedirections()
{
    d_insertPipe.readFrom(STDIN_FILENO);
//    d_extractPipe.writtenBy(STDOUT_FILENO);
//    d_errPipe.writtenBy(STDERR_FILENO);
}

