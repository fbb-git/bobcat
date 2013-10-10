inline MailHeaders::const_hdr_iterator 
&MailHeaders::const_hdr_iterator::operator--()
{
    d_current = lookdown(d_current);
    return *this;
}
