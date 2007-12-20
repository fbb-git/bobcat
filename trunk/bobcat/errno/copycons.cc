#include "errno.ih"

Errno::Errno(Errno const &other)
:
    ostringstream(other.str()),
    d_errno(other.d_errno),
    d_msg(other.d_msg)
{}
