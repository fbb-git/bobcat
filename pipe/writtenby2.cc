#include "pipe.ih"

void Pipe::writtenBy(int const *fd, size_t n)
{
    close(d_fd[READ]);

    for (size_t idx = 0; idx < n; ++idx)
    {
        Redirector r(d_fd[WRITE]);
        r.swallow(fd[idx]);
    }

    close(d_fd[WRITE]);
}
