#include "pipe.ih"

Pipe::Pipe()
{
    if (int err = pipe(d_fd))
        throw Errno(err, "Pipe::Pipe()");
}

