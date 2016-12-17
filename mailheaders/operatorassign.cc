#include "mailheaders.ih"

MailHeaders &MailHeaders::operator=(MailHeaders &&tmp)
{
    fswap(*this, tmp, d_hdr);
    return *this;
}

