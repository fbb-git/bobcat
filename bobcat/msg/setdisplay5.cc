#include "msg.ih"

void Msg::setDisplay(Type type, ostream &stream)
{
    StreamInfo &si = s_streams[type];

    prepareStream(si);
    si.out.rdbuf(stream.rdbuf());
}
