#include "mailheaders.hh"

MailHeaders &MailHeaders::operator=(MailHeaders &&tmp)
{
    fswap(*this, tmp);
    return *this;
}

