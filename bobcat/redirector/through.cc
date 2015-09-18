#include "redirector.hh"

void Redirector::through(int alternateFd) const
{
    if (dup2(d_fd, alternateFd) < 0)
        throw Exception() << "Redirector::through(): " << errnodescr;

    ::close(d_fd);
}
