inline bool MailHeaders::const_hdr_iterator::caseFull(
                                    string const &hdr, string const &key)
{
    return String::lc(hdr.substr(0, hdr.find(':'))) == key;
}
