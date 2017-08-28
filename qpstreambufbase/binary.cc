#include "qpstreambufbase.ih"

void QPStreambufBase::binary()
{
    escape('\n');
    flush();
}
