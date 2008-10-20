#include "process.ih"

void Process::setPipes(iomode mode)
{
    d_mode = mode;

    d_child_inp.reset(mode & CIN ?                       newPipe() : 0);
    d_child_outp.reset(mode & (COUT | MERGE_COUT_CERR) ? newPipe() : 0);
    d_child_errp.reset(mode & CERR ?                     newPipe() : 0);
}


