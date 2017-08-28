#include "qpstreambufbase.ih"

void QPStreambufBase::text()
{
    flush();
    d_buffer += '\n';
}
