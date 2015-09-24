#include "pipe.ih"

void Pipe::writtenBy(int fd)
{
    close(d_fd[READ]);

    Redirector  d(d_fd[WRITE]);
    d.swallow(fd);

    close(d_fd[WRITE]);
}
