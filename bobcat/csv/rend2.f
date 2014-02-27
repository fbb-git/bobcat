template <>
inline CSV::const_reverse_iterator<std::string> CSV::rend() const
{
    return const_reverse_iterator<std::string>(begin<std::string>());
}
