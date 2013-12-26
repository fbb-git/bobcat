#include "process.ih"

void Process::start(size_t bufferSize, 
                    IOMode mode, ProcessType type, size_t timeLimit)
{
    if (d_active)
        stop();

    size_t savedBufSize = bufSize();
    setBufSize(bufferSize);

    d_active = true;
    d_timeLimit = timeLimit;
    d_processType = type;

    rmBackticks();                      // rm backticks from d_command

    sanitizeIOMode(mode);

    forking();

    setBufSize(savedBufSize);
    d_mode = d_setMode;                     // revert to the default process
    d_processType = d_setProcessType;       // parameters for a next run
    d_timeLimit = d_setTimeLimit;
}
