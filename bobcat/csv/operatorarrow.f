template <>
inline std::string const *CSV::const_iterator<std::string>::operator->() const
{
    return &d_csv->get<std::string>(d_idx);
}

