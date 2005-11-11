#include "mailheaders.ih"

void MailHeaders::continueHeader(string const &line, HdrLine *hdrLine)
{
    if (!hdrLine)                                     // no header-indices yet
        throw Errno("MailHeaders::continueHeaders()") << insertable <<
            "First mail header doesn't start with non-blank char." <<
            throwable;
     
    hdrLine->push_back(size());
}





