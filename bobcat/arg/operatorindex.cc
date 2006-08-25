#include "arg.ih"

char const *Arg::operator[](size_t idx) const
{
    return
        (idx >= nArgs()) ?
            0
        :
            d_argv[idx].c_str();
}
