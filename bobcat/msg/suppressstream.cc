#include "msg.ih"

void Msg::suppressStream(MsgStream *ms)
{
    if (not ms->good())
        return;

    *ms << flush;
    ms->setstate(ios::badbit);
}

