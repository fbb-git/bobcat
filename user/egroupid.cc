#include "user.hh"

size_t User::eGroupid() const
{
    return getegid();
}
