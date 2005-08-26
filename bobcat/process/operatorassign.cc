#include "process.ih"

int Process::operator=(std::string const &command)
{
    clear();

    *this <<
        (
            command.length() 
            && 
            *command.begin() == '`' && *command.rbegin() == '`' ?
                command.substr(1, command.length() - 2)
            :
                command
        );

    return execute();
}
