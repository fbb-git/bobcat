#include "stat.hh"

Stat::Stat(string const &name)
:
    d_name(name)
{
    init();
}
