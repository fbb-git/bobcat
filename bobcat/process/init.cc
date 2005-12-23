#include "process.ih"

void Process::init(std::string const &command, iomode mode)
{
    open(d_childCout, d_childCin);  // associate in/out streams

    if (command.length())
    {
        if (command[0] == '`' && *command.rbegin() == '`')
        {
            d_command = command.substr(1, command.length() - 2);
            start(d_waitSeconds, mode);
        }
        else
            d_command = command;
    }
}
