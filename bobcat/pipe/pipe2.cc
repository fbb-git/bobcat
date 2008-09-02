#include "pipe.ih"

Pipe::Pipe(int const *fd)
:
    d_err(0)
{
    d_fd[READ] = fd[READ];
    d_fd[WRITE] = fd[WRITE];
}
