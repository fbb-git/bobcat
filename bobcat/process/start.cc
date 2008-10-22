#include "process.ih"

void Process::start(size_t waitSeconds, iomode mode, ProcessType type)
{
    if (d_active)
        stop();

    d_active = true;
    d_waitSeconds = waitSeconds;
    d_processType = type;
    setIOMode(mode);

    setPipes();

    if (d_command[0] == '`' && *d_command.rbegin() == '`')  // rm backticks
        d_command = d_command.substr(1, d_command.length() - 2);

    forking();
}
