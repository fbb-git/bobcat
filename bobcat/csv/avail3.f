template <typename Type>
inline Type IUO::Avail<Type, IUO::STRING>::available(std::string const &field)
{
    if (field.empty())
        throw 1;

    return field;
}
