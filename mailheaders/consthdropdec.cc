#include "mailheaders.ih"

MailHeaders::const_hdr_iterator const
MailHeaders::const_hdr_iterator::operator--(int)
{
    const_hdr_iterator ret(d_mh, d_current);
    d_current = lookdown(d_current);

    return ret;
}

