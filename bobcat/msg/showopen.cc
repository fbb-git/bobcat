#include "msg.ih"

#include "../iuo/iuo"

void FBB::showOpen()
{
    static bool called = false;
    deprecated__(called, "FBB::Msg::open(...) functions are deprecated. "
                         "Use FBB::Errno::open functions instead");
}
