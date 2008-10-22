#include "process.ih"

void Process::initialize(size_t timeLimit, iomode mode, 
                         ProcessType processType)
{
    d_active = false;

    d_setTimeLimit = d_timeLimit = timeLimit;
    d_setProcessType = d_processType = processType; 
    d_setMode = sanitizeIOMode(mode);

    d_oldIn = -1;
    d_oldOut = -1; 
    d_oldErr = -1;

    open(d_childCout, d_childCin);
}
