#include "arg.hh"

char const *Arg::operator[](size_t idx) const
{
    return (*d_ptr)[idx];
}

