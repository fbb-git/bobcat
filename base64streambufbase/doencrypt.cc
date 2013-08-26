#include "base64streambufbase.ih"

void Base64StreambufBase::doEncrypt()
{
    d_action = &Base64StreambufBase::encrypt;
}

