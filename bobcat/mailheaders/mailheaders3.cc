#include "mailheaders.ih"

#include "../iuo/iuo"

MailHeaders::MailHeaders(MailHeaders const &&tmp)
:
    d_lines( move(tmp.d_lines) ),
    d_in(tmp.d_in),
    d_hdr( move(tmp.d_hdr) ),
    d_match(tmp.d_match)
{
    static bool called = false;
    deprecated__(called, "MailHeaders::MailHeaders(MailHeaders const &&tmp)");
}
