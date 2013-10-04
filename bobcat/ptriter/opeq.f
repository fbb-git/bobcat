template <typename Iterator>
bool PtrIter<Iterator>::operator==(PtrIter const &other) const
{
    return d_iter == other.d_iter;
}
