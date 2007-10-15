#include "process.ih"

void Process::setPipes(iomode mode)
{
    d_mode = mode;

    d_child_inp.reset(mode & CIN ? new Pipe : 0);

    if (mode & MERGE_COUT_CERR)
    {
        d_child_errp.reset(0);
        d_child_outp.reset(new Pipe);
    }
    else
    {
        d_child_outp.reset(mode & COUT ? new Pipe : 0);
        d_child_errp.reset(mode & CERR ? new Pipe : 0);
    }
}
