template <typename Type>
inline CSV::const_reverse_iterator<Type> CSV::rend() const
{
    return const_reverse_iterator<Type>(begin<Type>());
}
