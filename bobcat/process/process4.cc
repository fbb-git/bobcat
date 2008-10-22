#include "process.ih"

Process::Process(size_t waitSeconds, iomode mode, ProcessType processType, 
                                                  string const &command)
:
    d_childCin(0),
    d_childCout(0),
//    d_childCerr(0),   

    d_mode(mode),
    d_command(command),
    d_processType(processType),
    d_waitSeconds(waitSeconds),
    d_active(false)
{
    open(d_childCout, d_childCin);
}
