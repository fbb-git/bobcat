#include "iuo.ih"

namespace FBB
{
    void deprecated__(bool &called, char const *msg)
    {
        if (called)
            return;
    
        cerr << msg << '\n';
        called = true;
    }
}

