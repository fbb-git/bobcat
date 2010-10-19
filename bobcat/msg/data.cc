#include "msg.ih"

ostringstream Msg::s_msg;

MsgStream FBB::emsg(&std::cout, UINT_MAX - 1,   "Error");
MsgStream FBB::fmsg(&std::cout, UINT_MAX,       "Fatal", true);
MsgStream FBB::imsg(&std::cout, UINT_MAX);
MsgStream FBB::wmsg(&std::cout, UINT_MAX,       "Warning");

MsgStream *Msg::s_msgStream[] = 
    {
        &emsg,
        &fmsg,
        &imsg,
        &wmsg
    };
