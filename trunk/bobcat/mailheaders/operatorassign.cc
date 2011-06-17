#include "mailheaders.ih"

MailHeaders &MailHeaders::operator=(MailHeaders &&tmp)
{
    fswap(*this, tmp);
    return *this;
}

