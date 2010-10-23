#include "msg.ih"

void FBB::spool(ostream &out)
{
    if (!Msg::s_display)
        return;

    ostringstream &os = dynamic_cast<ostringstream &>(out);

    Msg::s_info << os.str() << flush;
}

