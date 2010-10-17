#include "msg.ih"

void FBB::spool(ostream &out)
{
    Msg::StreamInfo &si = Msg::s_streams[Msg::INFO];

    if (!si.out.good())
        return;

    ostringstream &os = dynamic_cast<ostringstream &>(out);

    si.out << os.str() << flush;
}

