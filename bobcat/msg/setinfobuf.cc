#include "msg.ih"

streambuf *Msg::setInfoBuf(streambuf *newBuffer, bool onOff)
{
    static bool shown = false;

    if (!shown)
    {
        shown = true;
        cerr << "\n"
                "FBB::Msg::setInfoBuf is DEPRECATED. Use\n"
                "setDisplay(FBB::Msg::INFO, newBuffer) instead\n"
                "\n";
    }

    if (newBuffer)
        setDisplay(INFO, newBuffer);

    setDisplay(onOff);

    return rdbuf(INFO);
}
