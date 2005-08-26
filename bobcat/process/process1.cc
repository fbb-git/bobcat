#include "process.ih"

Process::Process(std::string const &command)
:
    d_out(0),
    d_err(0),
    d_ret(-1)
{
    if (command.length())
    {
        if (*command.begin() == '`' && *command.rbegin() == '`')
        {
            *this << command.substr(1, command.length() - 2);
            execute();
        }
        else
            *this << command;
    }
}
