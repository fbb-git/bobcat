template <typename Type>
inline Type IUO::Avail<Type, IUO::STRING>::get(std::string const &field)
{
    if (field.empty())
        throw 1;

    return field;
}
