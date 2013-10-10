inline bool MailHeaders::const_hdr_iterator::initial(
                                    string const &hdr, string const &key)
{
    return hdr.substr(0, hdr.find(':')).find(key) == 0;
}
