#include "mailheaders.ih"

MailHeaders &MailHeaders::operator=(MailHeaders const &&tmp)
{
    fswap(*this, const_cast<MailHeaders &>(tmp));
    return *this;
}

