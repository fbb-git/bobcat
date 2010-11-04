#include "process.ih"

Process::Process(std::string const &command)
:
    d_command(command),
    d_childCin(0),
    d_childCout(0),
    d_childCerr(0)
{
    initialize(0, CIN | COUT | CERR, NO_PATH);
}
