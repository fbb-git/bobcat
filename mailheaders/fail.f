inline bool MailHeaders::const_hdr_iterator::fail(
                                    string const &hdr, string const &key)
{
    throw Exception(1) << "MailHeaders: setHeaderIterator() not called";
    return false;       // not reached
}
