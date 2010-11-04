#include "process.ih"

void Process::close(int fd)
{
    if (fd != -1)
        ::close(fd);
}
