#include "arg.ih"

size_t Arg::option(std::string const &optchars) const
{
    size_t count = 0;

    for (char const *cp = optchars.c_str(); *cp; ++cp)
        count += option(*cp);

    return count;
}
