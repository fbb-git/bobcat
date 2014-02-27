template <>
inline CSV::const_iterator<std::string> CSV::begin() const
{
    return const_iterator<std::string>(this, 0);
}
