#include "arg.ih"

size_t Arg__::nArgs() const
{
    return d_argv.size();
}

size_t Arg::nArgs() const
{
    return d_arg->nArgs();
}

