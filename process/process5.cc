#include "process.ih"

Process::Process(IOMode mode, ProcessType processType, 
                 size_t timeLimit, size_t bufSize, string const &command)
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
    d_setMode = sanitizeIOMode(mode);

            // connect the input and output streams to Process
    open(d_iChildOut, d_oChildIn);
}


