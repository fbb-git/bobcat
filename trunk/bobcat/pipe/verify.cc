#include "pipe.ih"

void Pipe::verify() const
{
    if (d_err)
        throw Errno(d_err, "Pipe::Pipe()");
}
