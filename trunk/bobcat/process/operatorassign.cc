#include "process.ih"

int Process::operator=(std::string const &command)
{
    int ret = stop();

    setCommand(command);

    start();
    return ret;
}
