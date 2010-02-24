#include "mailheaders.ih"

MailHeaders::MailHeaders(istream &in, Mode mode)
:
    d_in(in),
    d_match(FAIL)
{
    if (mode == READ)
        read();
}
