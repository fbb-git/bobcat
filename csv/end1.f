template <typename Type>
inline CSV::const_iterator<Type> CSV::end() const
{
    return const_iterator<Type>(this, size());
}
