#include "msg.ih"

streambuf *Msg::setInfoBuf(streambuf *newBuffer, bool onOff)
{
    if (newBuffer)
        setDisplay(INFO, newBuffer);

    setDisplay(onOff);

    return sbuf(INFO);
}
