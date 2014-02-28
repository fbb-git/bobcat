template <>
inline CSV::const_iterator<std::string> CSV::end() const
{
    return const_iterator<std::string>(this, size());
}
