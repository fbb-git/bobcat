#include "msg.ih"

void Msg::activateStream(MsgStream *ms)
{
    if (ms->good())
        return;

    ms->clear();
}

