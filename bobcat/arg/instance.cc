#include "arg.hh"

Arg &Arg::instance()
{
    if (!s_arg)
        throw Exception() << "Arg::instance(): not yet initialized";

    return *s_arg;
}
