#include "msg.ih"

std::streambuf *Msg::infoToWarning()
{
    static bool shown = false;

    if (!shown)
    {
        shown = true;
        cerr << "FBB::Msg::infoToWarning is deprecated. Use\n"
                "setDisplay(FBB::Msg::INFO, streambuf(FBB::Msg::WARNING)) "
                                                                "instead\n";
    }

    streambuf *old = s_streams[INFO].out.rdbuf();
    setDisplay(INFO, sbuf(WARNING));
    return old;
}

