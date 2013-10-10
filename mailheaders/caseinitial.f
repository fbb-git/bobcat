inline bool MailHeaders::const_hdr_iterator::caseInitial(
                                    string const &hdr, string const &key)
{
    return String::lc(hdr.substr(0, hdr.find(':'))).find(key) == 0;
}
