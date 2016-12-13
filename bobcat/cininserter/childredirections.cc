#include "cininserter.ih"

void CinInserter::childRedirections()
{
    d_oChildInPipe.readFrom(STDIN_FILENO);
}
