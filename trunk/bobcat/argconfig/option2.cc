#include "argconfig.ih"

size_t ArgConfig::option(std::string const &optchars) const
{
    size_t count = 0;
    char const *cp = optchars.c_str(); 

    while (*cp)
    {
        count += option(*cp);
        ++cp;
    }

    return count;
}
