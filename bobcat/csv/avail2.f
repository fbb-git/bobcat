template <typename Type>
inline Type IUO::Avail<Type, IUO::FLOAT>::get(std::string const &field)
{
    return static_cast<Type>(stold(field));
}
