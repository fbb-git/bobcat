#include "msg.ih"

void Msg::setActive(MsgStream *ms, bool active)
{
    if (active)
        ms->clear();
    else
        ms->setstate(ios::badbit);
}

