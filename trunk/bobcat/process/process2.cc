#include "process.ih"

Process::Process(iomode mode, std::string const &command)
:
    d_command(command),

    d_oChildIn(0),
    d_iChildOut(0),
    d_iChildErr(0)
{
    initialize(0, mode, NO_PATH);
}
