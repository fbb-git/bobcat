#include "msg.ih"

ostringstream &FBB::lineMsg()
{
    msg() << "Line " << Msg::s_line << ": ";
    return Msg::s_msg;
}
