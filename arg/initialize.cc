#include "arg.hh"

Arg &Arg::initialize(char const *optstring, int argc, char **argv)
{
    if (s_arg)
        throw Exception() << "Arg::initialize(): already initialized";

    s_arg = new Arg(optstring, argc, argv);

    return *s_arg;
}
