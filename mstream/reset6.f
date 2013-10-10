inline void Mstream::reset(std::streambuf *buf, size_t maxCount,
                           std::string const &tag, bool throwing)
{
    Mbuf::reset(buf, maxCount, tag, throwing);
}
