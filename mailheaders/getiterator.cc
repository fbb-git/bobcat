#include "mailheaders.ih"

MailHeaders::const_iterator 
        MailHeaders::getIterator(Where where) const
{
    if (!d_index.size())
        throw Errno(0, "MailHeaders") << insertable <<
            ": no header information available" <<
            throwable;

    if (d_match != FAIL)
    {
        size_t idx = lookup(d_hdr.c_str(), d_match);
             
        if (idx != string::npos)
            return where == BEGIN ? 
                    d_index[idx].second.begin()
                :
                    d_index[idx].second.end();
    }
    return d_index[0].second.end();
}


