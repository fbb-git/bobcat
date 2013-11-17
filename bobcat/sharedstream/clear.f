inline void SharedStream::clear()
{
    std::istream::clear();
    std::ostream::clear();
}
