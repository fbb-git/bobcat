#include "glob.hh"

Glob::Glob(Glob const &other)
{
    d_share = other.d_share;
    ++d_share->users;
}
