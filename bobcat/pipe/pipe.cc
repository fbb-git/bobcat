#include "pipe.ih"

Pipe::Pipe()  throw(Errno)
{
    if (pipe(d_fd))
        throw Errno("Pipe::Pipe()");
}
