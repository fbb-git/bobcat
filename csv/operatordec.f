template <typename Type>
CSV::const_iterator<Type> &CSV::const_iterator<Type>::operator--()
{
    --d_idx;
    return *this;
}
