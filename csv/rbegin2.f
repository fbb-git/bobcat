template <>
inline CSV::const_reverse_iterator<std::string> CSV::rbegin() const
{
    return const_reverse_iterator<std::string>(end<std::string>());
}
