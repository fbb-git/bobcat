#include "mailheaders.ih"

MailHeaders::const_iterator MailHeaders::const_hdr_iterator::lookup
                                        (const_iterator const &begin) const
{
    const_iterator next = 
            find_if(begin, d_mh->end(), 
                    [&](std::string const &header)
                    {
                        return (*d_comparator)(header, d_key);
                    }
            );
    return next;
}
