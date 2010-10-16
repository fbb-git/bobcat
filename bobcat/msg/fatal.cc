#include "msg.ih"

void FBB::fatal(ostream &out)
{
    Msg::StreamInfo &si = Msg::s_streams[Msg::FATAL];

    if (!si.out.good())
        return;

    ostringstream &os = dynamic_cast<ostringstream &>(out);

    si.out << "[Fatal] " << os.str() << endl;

    throw Errno(1);
}

