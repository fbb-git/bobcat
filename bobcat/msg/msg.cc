#include "msg.ih"

#include "../iuo/iuo"

ostringstream &FBB::msg()
{
    static bool called = false;
    deprecated__(called, "FBB::msg() is deprecated. "
                         "Use FBB::Mstream objects instead");

    Msg::s_msg.clear();
    Msg::s_msg.str("");
    return Msg::s_msg;
}
