#include "stat.hh"

bool Stat::set(string const &name)
{
    d_name = name;
    init();
    return !d_errno;
}
