inline Mstream::Mstream(std::streambuf *buf, size_t maxCount, 
                             std::string const &tag, bool throwing)
:
    Mbuf(buf, maxCount, tag, throwing),
    std::ostream(this)
{}
