#include "process.ih"

int Process::operator=(std::string const &command)
{
    int ret = stop();

    d_command = 
            command.length() 
            && 
            *command.begin() == '`' && *command.rbegin() == '`' ?
                command.substr(1, command.length() - 2)
            :
                command;

    start();
    return ret;
}
