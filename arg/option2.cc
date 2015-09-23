#include "arg.hh"

size_t Arg__::option(std::string const &optchars) const
{
    size_t count = 0;

    for (char const *cp = optchars.c_str(); *cp; ++cp)
        count += option(*cp);

    return count;
}

size_t Arg::option(std::string const &optchars) const
{
    return d_ptr->option(optchars);
}
