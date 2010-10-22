#include "msg.ih"

void Msg::setDisplay(Type type, std::string const &name)
{
    MsgStream *ms = s_msgStream[type];

    ms->reset();
    ms->open(name);
}
