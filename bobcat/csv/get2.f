template <>
inline std::string const &
                CSV::get<std::string>(size_t idx) const
{
    return d_field[idx];
}
