inline bool MailHeaders::const_hdr_iterator::casePartial(
                                    string const &hdr, string const &key)
{
    return String::lc(hdr.substr(0, hdr.find(':'))).find(key) != string::npos;
}
