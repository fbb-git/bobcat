#include "arg.ih"

char const **Arg::argPointers()
{
    if (!d_argPointer)
        d_argPointer = String::argv(d_argv);

    return d_argPointer;
}
