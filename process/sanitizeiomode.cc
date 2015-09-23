#include "process.hh"

Process::IOMode Process::sanitizeIOMode(IOMode mode)
{
    if (
        not (mode & PIPES_OK) 
        &&  
        (mode & (IN_PIPE | OUT_PIPE | CLOSE_ON_EXEC))
    )
        throw invalid_argument("IOModes IN_PIPE, OUT_PIPE and CLOSE_ON_EXIT "
                                                   "may not be specified");

    if ((mode & DIRECT) && (mode & ~DIRECT))
        throw invalid_argument("IOModes cannot be combined with DIRECT");
 
    if ((mode & IGNORE_CERR) && (mode & (CERR | MERGE_COUT_CERR)))
        throw invalid_argument(
            "IOMode IGNORE_CERR cannot be used with modes "
            "CERR or MERGE_COUT_CERR");

    if ((mode & IGNORE_COUT) && (mode & (COUT | MERGE_COUT_CERR)))
        throw invalid_argument(
            "IOMode IGNORE_COUT cannot be used with modes "
            "COUT or MERGE_COUT_CERR");

    if ((mode & MERGE_COUT_CERR) && (mode & (CERR | COUT)))
        throw invalid_argument(
            "IOMode MERGE_COUT_CERR cannot be used with modes COUT or CERR");

    return d_mode = mode;
}
