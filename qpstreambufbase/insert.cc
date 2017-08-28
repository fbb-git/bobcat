#include "qpstreambufbase.ih"

void QPStreambufBase::insert(int ch)
{
    if (isprint(ch) && ch != '=')
        d_pending += ch;
    else
        escape(ch);
}
