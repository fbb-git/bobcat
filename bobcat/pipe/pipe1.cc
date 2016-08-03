#include "pipe.ih"

Pipe::Pipe()
{
    if (pipe(d_fd))
        throw Exception{} << "Pipe::Pipe(): " << errnodescr;
}



