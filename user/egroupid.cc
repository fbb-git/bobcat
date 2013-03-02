#include "user.ih"

size_t User::eGroupid() const
{
    return getegid();
}
