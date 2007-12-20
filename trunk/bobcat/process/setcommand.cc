#include "process.ih"

void Process::setCommand(std::string const &command)
{
    if (command.length())
        d_command = 
            command[0] == '`' && *command.rbegin() == '`' ?
                command.substr(1, command.length() - 2)
            :
                command;
}
