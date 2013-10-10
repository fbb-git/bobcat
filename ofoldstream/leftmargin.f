inline size_t OFoldStream::leftMargin(std::ostream const &os)
{
    return OFoldStreambuf::leftMargin(os.rdbuf());
}
