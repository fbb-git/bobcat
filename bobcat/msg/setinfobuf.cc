#include "msg.ih"

streambuf *Msg::setInfoBuf(streambuf *newBuffer, bool onOff)
{
    static bool shown = false;

    if (!shown)
    {
        shown = true;
        cerr << "FBB::Msg::setInfoBuf is deprecated. Use\n"
                "setDisplay(FBB::Msg::INFO, newBuffer) instead\n";
    }

    if (newBuffer)
        setDisplay(INFO, newBuffer);

    setDisplay(onOff);

    return sbuf(INFO);
}
