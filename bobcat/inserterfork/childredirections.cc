#include "inserterfork.ih"

void InserterFork::childRedirections()
{
    d_oChildInPipe.readFrom(STDIN_FILENO);
}
