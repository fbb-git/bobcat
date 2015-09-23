#include "mailheaders.hh"

MailHeaders::const_iterator MailHeaders::const_hdr_iterator::lookdown
                                        (const_iterator const &begin) const
{
    return d_mh->begin() +
            (
                &*find_if(
                    const_reverse_iterator(begin), d_mh->rend(), 
                    [&](std::string const &header)
                    {
                        return (*d_comparator)(header, d_key);
                    }
                ) 
                -  &*d_mh->begin()
            );

}
