#include "pipe.hh"

int Pipe::writeOnly()
{
    close(d_fd[READ]);
    return d_fd[WRITE];
}
