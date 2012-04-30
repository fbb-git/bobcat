#include "arg.ih"

size_t Arg__::nLongOptions() const
{
    return d_nOptv;
}

size_t Arg::nLongOptions() const
{
    return d_arg->nLongOptions();
}

