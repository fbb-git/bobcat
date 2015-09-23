#include "pattern.hh"

Pattern::~Pattern()
{
    if (d_regex)
        destroy();
}    
