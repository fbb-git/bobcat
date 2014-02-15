template <typename Type>
ReverseIterator<Type>::ReverseIterator(Type const &value)
:
    std::reverse_iterator<Iterator<Type>>(Iterator<Type>(value))
{}
