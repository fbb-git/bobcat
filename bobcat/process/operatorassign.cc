#include "process.ih"

int Process::operator=(std::string const &command)
{
    int ret = stop();

    setCommand(command);

    start(bufSize(), d_mode, d_processType, d_timeLimit);
    return ret;
}
