#include "mailheaders.ih"

MailHeaders::const_iterator MailHeaders::const_hdr_iterator::lookup
(
    const_iterator const &begin
) const
{
    const_iterator next = 
    find_if(begin, d_mh->end(), 
            FnWrap::unary(d_comparator, d_key));
    return next;
}
