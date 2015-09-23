#include "pipe.hh"

void Pipe::readFrom(int const *fd, size_t n)
{
    close(d_fd[WRITE]);

    for (size_t idx = 0; idx < n; ++idx)
    {
        Redirector r(d_fd[READ]);
        r.swallow(fd[idx]);
    }

    close(d_fd[READ]);
}
