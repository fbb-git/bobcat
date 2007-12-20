#include "pipe.ih"

int Pipe::writeOnly()
{
    close(d_fd[READ]);
    return d_fd[WRITE];
}
