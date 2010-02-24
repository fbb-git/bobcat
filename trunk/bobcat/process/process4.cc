#include "process.ih"

Process::Process(iomode mode, ProcessType processType, size_t timeLimit, 
                 string const &command)
:
    d_command(command),

    d_childCin(0),
    d_childCout(0),
    d_childCerr(0)
{
    initialize(timeLimit, mode, processType);
}
