#include "msg.ih"

ostringstream &FBB::lineMsg()
{
    imsg.showLineNrs(true);
    return Msg::s_msg;
}
