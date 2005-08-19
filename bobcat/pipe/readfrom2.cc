#include "pipe.ih"

void Pipe::readFrom(int const *fd, unsigned n)
{
    close(d_fd[WRITE]);

    for (unsigned idx = 0; idx < n; idx++)
    {
        Redirector r(d_fd[READ]);
        r.accessVia(fd[idx]);
    }

    close(d_fd[READ]);
}
