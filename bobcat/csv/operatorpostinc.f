template <typename Type>
CSV::const_iterator<Type> CSV::const_iterator<Type>::operator++(int)
{
    const_iterator<Type> tmp(*this);
    ++d_idx;
    return *this;
}
