#include "msg.ih"

void Msg::setDisplay(Type type, streambuf *buf)
{
    MsgStream *ms = s_msgStream[type];

    prepareStream(ms);
    ms->rdbuf(buf);
}
