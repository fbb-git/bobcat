#include "msg.ih"

void Msg::setDisplay(Type type, ostream &ostr, size_t maxCount,
                     string const &tag, bool throwing)
{
    s_msgStream[type]->reset(ostr, maxCount, tag, throwing);
}




