#include "msg.ih"

void FBB::info(ostream &out)
{
    Msg::StreamInfo &si = Msg::s_streams[Msg::INFO];

    if (!si.out.good())
        return;

    ostringstream &os = dynamic_cast<ostringstream &>(out);

    si.out << os.str() << endl;
}

