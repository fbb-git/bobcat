#include "process.ih"

Process::Process(std::string const &command, iomode mode)
:
    d_fdIn(-1),
    d_fdOut(-1),
    d_fdErr(-1),

    d_childCin(&d_childCinbuf),     // Prepare cin/cout/cerr overtake: 
    d_childCout(&d_childCoutbuf),   // set up buffers/streams
    d_childCerr(&d_childCerrbuf),   

    d_mode(mode),
    d_waitSeconds(0),
    d_active(false)
{
    open(d_childCout, d_childCin);  // associate in/out streams
    setCommand(command);
}
