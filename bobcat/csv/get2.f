template <>
inline typename IUO::CSV<std::string>::type
                CSV::get<std::string>(size_t idx) const
{
    return d_field[idx];
}
