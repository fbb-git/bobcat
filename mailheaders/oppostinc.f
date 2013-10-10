inline MailHeaders::const_hdr_iterator 
MailHeaders::const_hdr_iterator::operator++(int)
{
    return const_hdr_iterator(d_mh, d_current++);
}
