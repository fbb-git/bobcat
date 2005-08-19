#include "pipe.ih"

void Pipe::writtenBy(int const *fd, unsigned n)
{
    close(d_fd[READ]);

    for (unsigned idx = 0; idx < n; idx++)
    {
        Redirector r(d_fd[WRITE]);
        r.accessVia(fd[idx]);
    }

    close(d_fd[WRITE]);
}
