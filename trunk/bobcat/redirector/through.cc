#include "redirector.ih"

void Redirector::through(int alternateFd) const
{
    if (dup2(d_fd, alternateFd) < 0)
        throw Errno("Redirector::through()");

    ::close(d_fd);
}
