#include "pattern.ih"

void Pattern::newRegex(string const &pattern, int options)
{
    try
    {
        d_regex = 
            new Regex(pattern, options);
    }
    catch(...)
    {
        delete d_regex;
        throw;
    }
}
