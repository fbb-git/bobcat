#include "process.ih"

void Process::initialize(size_t timeLimit, iomode mode, 
                         ProcessType processType)
{
    d_active = false;

    d_setTimeLimit = d_timeLimit = timeLimit;
    d_setProcessType = d_processType = processType; 
    d_setMode = sanitizeIOMode(mode & ~(IN_PIPE | OUT_PIPE | CLOSE_ON_EXEC));

    open(d_iChildOut, d_oChildIn);
}
