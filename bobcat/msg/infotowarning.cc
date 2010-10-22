#include "msg.ih"

std::streambuf *Msg::infoToWarning()
{
    static bool shown = false;

    if (!shown)
    {
        shown = true;
        cerr << "\n"
                "FBB::Msg::infoToWarning is DEPRECATED. Use "
                                                "setDisplay(INFO, wmsg)\n"
                "\n";
    }

    streambuf *old = imsg.rdbuf();
    setDisplay(INFO, wmsg);

    return old;
}

