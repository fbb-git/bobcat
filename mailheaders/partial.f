inline bool MailHeaders::const_hdr_iterator::partial(
                                    string const &hdr, string const &key)
{
    return hdr.substr(0, hdr.find(':')).find(key) != string::npos;
}
