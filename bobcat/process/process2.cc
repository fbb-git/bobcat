#include "process.ih"

Process::Process(iomode mode, std::string const &command)
:
    d_childCin(0),
    d_childCout(0),
//    d_childCerr(0),   

    d_mode(mode),
    d_command(command),
    d_processType(NO_PATH),
    d_waitSeconds(0),
    d_active(false)
{
    open(d_childCout, d_childCin);
}
