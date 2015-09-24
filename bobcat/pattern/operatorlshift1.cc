#include "pattern.ih"

Pattern &Pattern::operator<<(int matchOptions)
{
    d_matchOptions = matchOptions;
    return *this;
}
