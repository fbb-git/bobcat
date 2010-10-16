#include "msg.ih"

void FBB::warning(ostream &out)
{
    Msg::StreamInfo &si = Msg::s_streams[Msg::WARNING];

    if (!si.out.good())
        return;

    ++Msg::s_warnCount;

    ostringstream &os = dynamic_cast<ostringstream &>(out);

    si.out << Msg::s_warning << os.str() << endl;
}

