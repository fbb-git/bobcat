#include "process.ih"

Process::iomode Process::sanitizeIOMode(iomode mode)
{
    d_mode = mode & ~(IN_PIPE | OUT_PIPE | CLOSE_ON_EXEC);

    if (d_mode & COUT)                  // overrules IGNORE_COUT
        d_mode &= ~(IGNORE_COUT);

    if (d_mode & CERR)                  // overrules IGNORE_CERR
        d_mode &= ~IGNORE_CERR;

    if (d_mode & MERGE_COUT_CERR)       // overrules either COUT or CERR
        d_mode &= ~(COUT | CERR);

    return d_mode;
}

