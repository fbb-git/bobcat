inline size_t OFoldStreambuf::rightMargin(std::streambuf const *buffer)
{
    return (*findOFoldStreambuf(buffer))->d_rightMargin;
}
