#include "arg.ih"

Arg &Arg::getInstance() throw (Errno)
{
    if (!s_arg)
        throw Errno("Arg::getInstance(): not yet initialized");

    return *s_arg;
}
