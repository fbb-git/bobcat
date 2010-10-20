#include "msg.ih"

ostringstream &FBB::msg()
{
    static bool shown = false;

    if (!shown)
    {
        shown = true;
        cerr << "\n"
                "In namespace FBB: msg(), lineMsg(), err, fatal, info, spool "
                "and warning\n"
                "are all DEPRECATED. Use imsg, emsg, fmsg and wmsg instead\n"
                "\n";
    }

    Msg::s_msg.clear();
    Msg::s_msg.str("");
    return Msg::s_msg;
}
