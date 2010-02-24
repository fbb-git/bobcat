#include "mailheaders.ih"

MailHeaders::const_iterator MailHeaders::const_hdr_iterator::lookdown
(
    const_iterator const &begin
) const
{
    return d_mh->begin() +
            (
                &*find_if(const_reverse_iterator(begin), d_mh->rend(), 
                        FnWrap1c<string const &, string const &, bool>
                        (d_comparator, d_key)) 
                -  &*d_mh->begin()
            );

}
