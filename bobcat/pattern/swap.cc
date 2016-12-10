#include "pattern.ih"

void Pattern::swap(Pattern &other)
{
    fswap(*this, other, d_text);
}

