#include "msg.ih"

std::streambuf *Msg::infoToWarning()
{
    static bool shown = false;

    if (!shown)
    {
        shown = true;
        cerr << "\n"
                "FBB::Msg::infoToWarning is DEPRECATED. Use "
                "imsg.msgbuf(wmsg.msgbuf())\n"
                "\n";
    }

    streambuf *old = imsg.msgbuf();
//    imsg.msgbuf(wmsg.msgbuf());

    return old;
}

