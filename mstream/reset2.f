inline void Mstream::reset(std::string const &name)
{
    Mbuf::reset(name, maxCount(), tag(), throws());
}
