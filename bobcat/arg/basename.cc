#include "arg.ih"

std::string const &Arg__::basename() const
{
    return d_base;
}

std::string const &Arg::basename() const
{
    return d_arg->basename();
}


