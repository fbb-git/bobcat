#include "msg.ih"

void Msg::setDisplay(Type type, MsgStream &mstream)
{
    MsgStream *ms = s_msgStream[type];

    ms->reset();
    ms->rdbuf(mstream.rdbuf());
    ms->setstate(mstream.rdstate());
}
