template <typename Type, size_t category>
Type IUO::Avail<Type, category>::get(std::string const &field)
{
    size_t pos;
    long long value = stoll(field, &pos);
    if (pos != field.length())
        throw 1;
    return static_cast<Type>(value);
}

