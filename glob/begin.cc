#include "glob.ih"

char const *const *Glob::begin() const
{
    return d_share->begin;
}

