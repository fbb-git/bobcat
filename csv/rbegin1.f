template <typename Type>
inline CSV::const_reverse_iterator<Type> CSV::rbegin() const
{
    return const_reverse_iterator<Type>(end<Type>());
}



