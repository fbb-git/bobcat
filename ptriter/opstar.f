template <typename Iterator>
typename PtrIter<Iterator>::PtrType PtrIter<Iterator>::operator*() const
{
    return &*d_iter;
}
