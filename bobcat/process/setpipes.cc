#include "process.ih"

void Process::setPipes(iomode mode)
{
    d_mode = mode;

    d_child_inp.reset(mode & CIN ? newPipe() : 0);

    if (mode & MERGE_COUT_CERR)
    {
        d_child_errp.reset(0);
        d_child_outp.reset(newPipe());
    }
    else
    {
        d_child_outp.reset(mode & COUT ? newPipe() : 0);
        d_child_errp.reset(mode & CERR ? newPipe() : 0);
    }
}
