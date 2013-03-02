#include "stat.ih"

Stat::Stat(string const &name)
:
    d_name(name)
{
    init();
}
