#include "mailheaders.ih"

#include "../iuo/iuo"

MailHeaders &MailHeaders::operator=(MailHeaders const &&tmp)
{
    static bool called = false;
    deprecated__(called, "MailHeaders::operator=(MailHeaders const &&tmp) is "
                        "deprecated. Please recompile this program");
    fswap(*this, const_cast<MailHeaders &>(tmp));
    return *this;
}

