#include "mailheaders.ih"

MailHeaders::const_iterator MailHeaders::const_hdr_iterator::lookup
(
    const_iterator const &begin
) const
{
    const_iterator next = 
    find_if(begin, d_mh->end(), 
            FnWrap1c<string const &, string const &, bool>
                    (d_comparator, d_key));
    return next;
}
