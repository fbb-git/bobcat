#include "base64streambufbase.hh"

void Base64StreambufBase::doEncrypt()
{
    d_action = &Base64StreambufBase::encrypt;
}

