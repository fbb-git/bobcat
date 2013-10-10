inline size_t OFoldStreambuf::leftMargin(std::streambuf const *buffer)
{
    return (*findOFoldStreambuf(buffer))->d_indent;
}
