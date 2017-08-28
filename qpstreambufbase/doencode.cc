#include "qpstreambufbase.ih"

void QPStreambufBase::doEncode(bool binary)
{
    d_encode = binary? &QPStreambufBase::binary : &QPStreambufBase::text;
    d_action = &QPStreambufBase::encode;
}

