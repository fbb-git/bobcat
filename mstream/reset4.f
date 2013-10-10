inline void Mstream::reset(std::ostream &ostr, size_t maxCount,
                           std::string const &tag, bool throwing)
{
    Mbuf::reset(ostr.rdbuf(), maxCount, tag, throwing);
}
