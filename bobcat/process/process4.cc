#include "process.ih"

Process::Process(size_t waitSeconds, iomode mode, ProcessType processType, 
                                                  string const &command)
:
    d_command(command),

    d_childCin(0),
    d_childCout(0),
    d_childCerr(0)
{
    initialize(waitSeconds, mode, processType);
}
