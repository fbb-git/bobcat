inline size_t OFoldStream::rightMargin(std::ostream const &os)
{
    return OFoldStreambuf::rightMargin(os.rdbuf());
}
