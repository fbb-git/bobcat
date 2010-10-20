#include "msg.ih"

ostringstream Msg::s_msg;

MsgStream *Msg::s_msgStream[] = 
    {
        &emsg,
        &fmsg,
        &imsg,
        &wmsg
    };
