inline void OFoldStreambuf::writeNonWs() const
{
    out().write(d_nonWs.data(), d_nonWs.length());
}
