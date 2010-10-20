#include "msg.ih"

std::streambuf *Msg::infoToWarning()
{
    static bool shown = false;

    if (!shown)
    {
        shown = true;
        cerr << "\n"
                "FBB::Msg::infoToWarning is DEPRECATED. Use\n"
                "setDisplay(FBB::Msg::INFO, streambuf(FBB::Msg::WARNING)) "
                                                                "instead\n"
                "\n";
    }

    streambuf *old = s_msgStream[INFO]->rdbuf();
    setDisplay(INFO, rdbuf(WARNING));
    return old;
}

