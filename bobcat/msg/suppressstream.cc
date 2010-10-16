#include "msg.ih"

void Msg::suppressStream(StreamInfo &si)
{
    if (not si.out.good())
        return;

    si.out << flush;
    si.out.setstate(ios::failbit);
}

