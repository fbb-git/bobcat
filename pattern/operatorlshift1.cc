#include "pattern.hh"

Pattern &Pattern::operator<<(int matchOptions)
{
    d_matchOptions = matchOptions;
    return *this;
}
