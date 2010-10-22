#include "msg.ih"

void Msg::setDisplay(Type type, ostream &ostr, size_t maxCount,
                     string const &tag, bool throwing)
{
    MsgStream *ms = s_msgStream[type];

    ms->reset(ostr, maxCount, tag, throwing);
}
