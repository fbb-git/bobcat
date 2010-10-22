#include "msg.ih"

streambuf *Msg::setInfoBuf(streambuf *newBuffer, bool onOff)
{
    static bool shown = false;

    if (!shown)
    {
        shown = true;
        cerr << "\n"
                "FBB::Msg::setInfoBuf is DEPRECATED. Instead use "
                                                            "`setDisplay'\n"
                "\n";
    }

    if (newBuffer)
        imsg.rdbuf(newBuffer);

    setDisplay(onOff);

    return imsg.rdbuf();
}
