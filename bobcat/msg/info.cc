#include "msg.ih"

void FBB::info(ostream &out)
{
    if (!Msg::s_display)
        return;

    ostringstream &os = dynamic_cast<ostringstream &>(out);

    Msg::s_info << os.str() << endl;
}

