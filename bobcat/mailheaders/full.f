inline bool MailHeaders::const_hdr_iterator::full(
                                    string const &hdr, string const &key)
{
    return hdr.substr(0, hdr.find(':')) == key;
}
