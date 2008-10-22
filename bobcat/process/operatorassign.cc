#include "process.ih"

int Process::operator=(std::string const &command)
{
    int ret = stop();

    setCommand(command);

    start(d_mode, d_processType, d_waitSeconds);
    return ret;
}
