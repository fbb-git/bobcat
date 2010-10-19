#include "msg.ih"

void Msg::setDisplay(Type type, ostream &stream)
{
    MsgStream *ms = s_msgStream[type];

    prepareStream(ms);
    ms->rdbuf(stream.rdbuf());
}
