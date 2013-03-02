#include "redirector.ih"

void Redirector::accessVia(int alternateFd) const throw (Errno)
{
    if (dup2(d_fd, alternateFd) < 0)
        throw Errno("Redirector::accessVia()");
}
