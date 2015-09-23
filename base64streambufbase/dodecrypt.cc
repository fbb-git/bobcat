#include "base64streambufbase.hh"

void Base64StreambufBase::doDecrypt()
{
    d_action = &Base64StreambufBase::decrypt;
//    setBuffer();
}

