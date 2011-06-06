#include "iuo.ih"

namespace FBB
{
    void deprecated__(bool &called, char const *msg)
    {
        if (called)
            return;
    
        cerr << "[Warning] " << msg << 
            " is deprecated.\n"
            "Recompile this program to remove this warning\n";
        called = true;
    }
}

