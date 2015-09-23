#include "process.hh"

void Process::close(int fd)
{
    if (fd != -1)
        ::close(fd);
}
