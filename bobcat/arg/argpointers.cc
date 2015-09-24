#include "arg.ih"

char const **Arg__::argPointers()
{
    if (!d_argPointer)
        d_argPointer = String::argv(d_argv);

    return d_argPointer;
}

char const **Arg::argPointers()
{
    return d_ptr->argPointers();
}
