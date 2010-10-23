#include "msg.ih"

ostringstream &FBB::msg()
{
    Msg::s_msg.clear();
    Msg::s_msg.str("");
    return Msg::s_msg;
}
