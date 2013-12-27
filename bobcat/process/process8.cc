#include "process.ih"

Process::Process(size_t bufSize, IOMode mode, ProcessType processType, 
                 size_t timeLimit, string const &command)
:
    d_active(false),
    d_timeLimit(timeLimit),
    d_processType(processType),

    d_setTimeLimit(timeLimit),
    d_setProcessType(processType),

    d_command(command),

    d_oChildIn(0),          // initialize the streams with 0-buffers
    d_iChildOut(0),
    d_iChildErr(0),

    d_data(new ProcessData(bufSize))
{
#ifdef BOBCAT_DIY_CLOEXEC_
    d_data->d_closedByChild = 0;
#endif

    d_setMode = sanitizeIOMode(mode);

            // connect the input and output streams to Process
    open(d_iChildOut, d_oChildIn);
}


