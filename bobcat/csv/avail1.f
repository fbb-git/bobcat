template <typename Type, size_t category>
inline Type IUO::Avail<Type, category>::available(std::string const &field)
{
    return static_cast<Type>(stoll(field));
}
