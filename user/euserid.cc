#include "user.ih"

size_t User::eUserid() const
{
    return geteuid();
}

