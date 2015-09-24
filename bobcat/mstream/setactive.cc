#include "mstream.ih"

bool Mstream::setActive(bool ifTrue)
{
    if (ifTrue)
        on();
    else
        off();
    
    return ifTrue;
}

