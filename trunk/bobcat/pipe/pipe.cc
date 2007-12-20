#include "pipe.ih"

Pipe::Pipe()
{
    if (pipe(d_fd))
        throw Errno("Pipe::Pipe()");
}
