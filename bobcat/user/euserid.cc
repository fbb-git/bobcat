#include "user.hh"

size_t User::eUserid() const
{
    return geteuid();
}

