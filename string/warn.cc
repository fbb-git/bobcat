#include <iostream>

#include "string.ih"

namespace 
{
bool warned = false;
}

void String::warn()
{
    if (warned)
        return;
    warned = true;

    cerr << "Using FBB::String constructors is deprecated.\n"
            "Consult string(3bobcat) for details" << endl;
}
