#include "process.ih"

Process::Process(size_t waitSeconds, std::string const &command, iomode mode)
:
    d_childCin(&d_childCinbuf),     // Prepare to take over cin/cout/cerr
    d_childCout(&d_childCoutbuf),   // set up buffers/streams
    d_childCerr(&d_childCerrbuf),   
    d_mode(mode),
    d_waitSeconds(waitSeconds),
    d_active(false)
{
    setCommand(command);
}
