#include "glob.ih"

void Glob::copy(Glob const &other)
{
    d_share = other.d_share;
    ++d_share->users;
}
