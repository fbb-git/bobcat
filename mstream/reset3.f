inline void Mstream::reset(std::streambuf *buf)
{
    Mbuf::reset(buf, maxCount(), tag(), throws());
}
