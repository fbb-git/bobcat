#include "mailheaders.ih"

MailHeaders::const_hdr_iterator::const_hdr_iterator
(
    MailHeaders const *mh, MailHeaders::const_iterator begin
)
:
    d_mh(mh),
    d_key
    (
        static_cast<int>(mh->d_match) <
        static_cast<int>(MailHeaders::caseInsensitive) ?
            d_mh->d_hdr
        :
            String::lc(d_mh->d_hdr)
    ),
    d_comparator(s_comparator[mh->d_match]),
    d_current(lookup(begin))
{}
