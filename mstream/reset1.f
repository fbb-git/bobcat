inline void Mstream::reset(std::ostream &ostr)
{
    Mbuf::reset(ostr.rdbuf(), maxCount(), tag(), throws());
}
