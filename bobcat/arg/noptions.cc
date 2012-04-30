#include "arg.ih"

size_t Arg__::nOptions() const
{
    return d_nOptv;
}

size_t Arg::nOptions() const
{
    return d_arg->nOptions();
}

