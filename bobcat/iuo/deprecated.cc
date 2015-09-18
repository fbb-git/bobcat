#include "iuo.hh"

namespace FBB
{
    void deprecated__(bool &called, char const *msg)
    {
        if (called)
            return;
    
        cerr << "[Warning] " << msg << 
            " is deprecated.\n"
            "Avoid its use, see the man-page for alternatives.\n";
        called = true;
    }
}

