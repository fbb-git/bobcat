#include "process.ih"

void Process::initialize(size_t waitSeconds, iomode mode, 
                         ProcessType processType)
{
    d_active = false;

    d_waitSeconds = waitSeconds;
    d_processType = processType; 

    d_oldIn = -1;
    d_oldOut = -1; 
    d_oldErr = -1;

    setIOMode(mode);

    open(d_childCout, d_childCin);
}
