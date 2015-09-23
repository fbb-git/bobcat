#include "process.hh"

void Process::newPipes()
{
    if ((d_setMode & CIN) && not (d_setMode & IN_PIPE))
        newPipe(d_oChildInPipe);

    if ((d_mode & (COUT |  MERGE_COUT_CERR)))
        newPipe(d_iChildOutPipe);

    if (d_mode & CERR)
        newPipe(d_iChildErrPipe);
}






