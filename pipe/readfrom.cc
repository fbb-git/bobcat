#include "pipe.ih"

void Pipe::readFrom(int fd)
{
    close(d_fd[WRITE]);

    Redirector  d(d_fd[READ]);
    d.swallow(fd);

    close(d_fd[READ]);
}
