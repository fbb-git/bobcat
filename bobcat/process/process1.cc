#include "process.ih"

Process::Process(std::string const &command, iomode mode)
:
    d_childCin(&d_childCinbuf),     // Prepare cin/cout/cerr overtake: 
    d_childCout(&d_childCoutbuf),   // set up buffers/streams
    d_childCerr(&d_childCerrbuf),   
    d_ret(-1),
    d_mode(mode)
{
    open(d_childCout, d_childCin);  // associate in/out streams

    if (command.length())
    {
        if (command[0] == '`' && *command.rbegin() == '`')
        {
            d_command = command.substr(1, command.length() - 2);
            start(mode);
        }
        else
            d_command = command;
    }
}
