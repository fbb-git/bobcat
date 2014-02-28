template <typename Type>
Type IUO::Avail<Type, IUO::FLOAT>::get(std::string const &field)
{
    size_t pos;
    long double value = stold(field, pos);
    if (pos != field.length())
        throw 1;
    return static_cast<Type>(value);
}
