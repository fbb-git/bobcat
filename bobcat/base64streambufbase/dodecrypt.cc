#include "base64streambufbase.ih"

void Base64StreambufBase::doDecrypt()
{
    d_action = &Base64StreambufBase::decrypt;
//    setBuffer();
}

