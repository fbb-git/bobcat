#include "msg.ih"

void Msg::setDisplay(Type type, streambuf *buf)
{
    StreamInfo &si = s_streams[type];

    prepareStream(si);
    si.out.rdbuf(buf);
}
