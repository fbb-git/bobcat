inline Mstream::Mstream(std::ostream &ostr, size_t maxCount, 
                             std::string const &tag, bool throwing)
:
    Mbuf(ostr.rdbuf(), maxCount, tag, throwing),
    std::ostream(this)
{}
