#include "msg.ih"

void Msg::setDisplay(Type type, std::string const &name)
{
    StreamInfo &si = s_streams[type];

    prepareStream(si);

    open(si.fout, name);
    si.out.rdbuf(si.fout.rdbuf());
}
