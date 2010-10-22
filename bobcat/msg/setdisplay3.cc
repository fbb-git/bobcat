#include "msg.ih"

void Msg::setDisplay(Type type, std::string const &name, size_t maxCount,
                     string const &tag, bool throwing)
{
    s_msgStream[type]->open(name, maxCount, tag, throwing);
}
