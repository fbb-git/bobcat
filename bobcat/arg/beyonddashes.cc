#include "arg.ih"

int Arg__::beyondDashes() const
{
    return d_beyondDashes;
}

int Arg::beyondDashes() const
{
    return d_arg->beyondDashes();
}

