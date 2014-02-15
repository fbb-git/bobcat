template <typename Type>
ReverseIterator<Type>::ReverseIterator(Iterator<Type> const &vi)
:
    std::reverse_iterator<Iterator<Type>>(vi)
{}
