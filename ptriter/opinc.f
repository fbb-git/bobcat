template <typename Iterator>
PtrIter<Iterator> &PtrIter<Iterator>::operator++()
{
    ++d_iter;
    return *this;
}
