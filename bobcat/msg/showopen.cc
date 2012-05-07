#include "msg.ih"

#include "../iuo/iuo"

void FBB::showOpen()
{
    static bool called = false;

    if (not called)
    {
        called = true;
        cerr << "[Warning] FBB::Msg::open(...) functions are deprecated.\n"
                         "Use FBB::Errno::open functions instead\n";
    }
}
