#include "process.ih"

Process::Process(std::string const &command, iomode mode)
:
    d_childCin(&d_childCinbuf),     // Prepare cin/cout/cerr overtake: 
    d_childCout(&d_childCoutbuf),   // set up buffers/streams
    d_childCerr(&d_childCerrbuf),   
    d_mode(mode),
    d_waitSeconds(1),
    d_active(false)
{
    setCommand(command);
}
