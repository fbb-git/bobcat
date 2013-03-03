#include "redirector.ih"

void Redirector::swallow(int alternateFd) const
{
    if (dup2(d_fd, alternateFd) < 0)
        throw Exception() << "Redirector::swallow(): " << errnodescr;
}
