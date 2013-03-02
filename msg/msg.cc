#include "msg.ih"

#include "../iuo/iuo"

ostringstream &FBB::msg()
{
    static bool called = false;

    if (not called)
    {
        called = true;
        cerr << "[Warning] FBB::msg() is deprecated.\n"
                         "Use FBB::Mstream objects instead\n";
    }

    Msg::s_msg.clear();
    Msg::s_msg.str("");
    return Msg::s_msg;
}
