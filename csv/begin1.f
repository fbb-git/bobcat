template <typename Type>
inline CSV::const_iterator<Type> CSV::begin() const
{
    return const_iterator<Type>(this, 0);
}
