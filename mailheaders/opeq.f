inline bool MailHeaders::const_hdr_iterator::operator==(
                                    const_hdr_iterator const &other) const
{
    return d_current == other.d_current;
}
