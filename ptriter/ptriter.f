template<typename Iterator>
PtrIter<Iterator> ptrIter(Iterator const &iter)
{
    return PtrIter<Iterator>(iter);
}
