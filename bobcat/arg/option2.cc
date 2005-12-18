#include "arg.ih"

unsigned Arg::option(std::string const &optchars) const
{
    unsigned count = 0;

    for (char const *cp = optchars.c_str(); *cp; cp++)
        count += option(*cp);

    return count;
}
