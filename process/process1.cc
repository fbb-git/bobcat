#include "process.ih"

Process::Process(std::string const &command, iomode mode)
:
    d_childCin(&d_childCinbuf),     // Prepare cin/cout/cerr overtake: 
    d_childCout(&d_childCoutbuf),   // set up buffers/streams
    d_childCerr(&d_childCerrbuf),   
    d_ret(-1),
    d_mode(mode),
    d_waitSeconds(1)
{
    init(command, mode);
}
