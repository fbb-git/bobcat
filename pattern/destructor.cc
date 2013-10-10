#include "pattern.ih"

Pattern::~Pattern()
{
    if (d_regex)
        destroy();
}    
