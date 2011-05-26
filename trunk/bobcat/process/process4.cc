#include "process.ih"

Process::Process(iomode mode, ProcessType processType, size_t timeLimit, 
                 string const &command)
:
    d_command(command),

    d_oChildIn(0),
    d_iChildOut(0),
    d_iChildErr(0)
{
    initialize(timeLimit, mode, processType);
}
