#include "process.ih"

void Process::start(iomode mode, ProcessType type, size_t waitSeconds)
{
    if (d_active)
        stop();

    d_active = true;
    d_waitSeconds = waitSeconds;
    d_processType = type;

    sanitizeIOMode(mode);
    setPipes();

    if (d_command[0] == '`' && *d_command.rbegin() == '`')  // rm backticks
        d_command = d_command.substr(1, d_command.length() - 2);

    forking();
}
