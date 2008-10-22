#include "process.ih"

void Process::initialize(size_t waitSeconds, iomode mode, 
                         ProcessType processType)
{
    d_active = false;

    d_setWaitSeconds = d_waitSeconds = waitSeconds;
    d_setProcessType = d_processType = processType; 
    d_setMode = sanitizeIOMode(mode);

    d_oldIn = -1;
    d_oldOut = -1; 
    d_oldErr = -1;

    open(d_childCout, d_childCin);
}
