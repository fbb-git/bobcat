#include "msg.ih"

void Msg::prepareStream(StreamInfo &si)
{
    si.out << flush;
    si.fout.close();
    si.out.clear();
}
