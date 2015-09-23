#include "mstream.hh"

bool Mstream::setActive(bool ifTrue)
{
    if (ifTrue)
        on();
    else
        off();
    
    return ifTrue;
}

