#include "pattern.hh"

bool Pattern::operator<<(std::string const &text)
try
{
    match(text, d_matchOptions);
    d_matchOptions = 0;
    return true;
}
catch (...)
{
    d_matchOptions = 0;
    return false;
}
