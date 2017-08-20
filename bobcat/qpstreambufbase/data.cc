#include "qpstreambufbase.ih"

string const QPStreambufBase::s_hexChars { "0123456789ABCDEF" };

void (QPStreambufBase::*QPStreambufBase::s_encode[])() =
{
    &QPStreambufBase::text,
    &QPStreambufBase::binary
};
    

