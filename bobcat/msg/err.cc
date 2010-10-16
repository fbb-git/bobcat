#include "msg.ih"

void FBB::err(ostream &out)
{
    Msg::StreamInfo &si = Msg::s_streams[Msg::ERROR];

    if (!si.out.good())
        return;

    ostringstream &os = dynamic_cast<ostringstream &>(out);

    si.out << "[Error " << ++Msg::s_count << "] " << os.str() << endl;

    if (Msg::s_count > Msg::s_maxCount)
        msg() << "More than " << Msg::s_maxCount << " errors encountered." << 
                fatal;
}
