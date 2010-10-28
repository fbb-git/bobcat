#include "msg.ih"

ostringstream &FBB::msg()
{
    static bool shown = false;

    if (!shown)
    {
        shown = true;
        cerr << "\n"
                "FBB::msg() is DEPRECATED and will be removed from BOBCAT in "
                                                "a future release\n"
                "Use FBB::Mstream objects instead\n"
                "\n";
    }

    Msg::s_msg.clear();
    Msg::s_msg.str("");
    return Msg::s_msg;
}
