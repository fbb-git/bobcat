inline Mstream::Mstream(std::string const &name, size_t maxCount, 
                             std::string const &tag, bool throwing)
:
    Mbuf(name, maxCount, tag, throwing),
    std::ostream(this)
{}
