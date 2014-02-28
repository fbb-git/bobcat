template <typename Type>
inline Iterator<Type>::Iterator(Type const &value)
:
    d_value(value),
    d_type(new Type)
{}
