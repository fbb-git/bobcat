// LinearMap(Iterator begin, Iterator end)

template <typename Key, typename Value, typename Alloc>
template <typename Iterator>
inline LinearMap<Key, Value, Alloc>::
    LinearMap(Iterator begin, Iterator end)
:
    Base(begin, end)
{}
