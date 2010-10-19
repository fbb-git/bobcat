#include "msg.ih"

void Msg::prepareStream(MsgStream *ms)
{
    *ms << flush;
    ms->close();
    ms->clear();
}
