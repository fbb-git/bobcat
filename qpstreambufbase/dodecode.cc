#include "qpstreambufbase.ih"

void QPStreambufBase::doDecode()
{
    d_action = &QPStreambufBase::decode;
//    setBuffer();
}

