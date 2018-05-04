// LinearMap(Iterator begin, Iterator end)

template <typename Key, typename Value>
template <typename Iterator>
inline LinearMap<Key, Value>::
    LinearMap(Iterator begin, Iterator end)
{
    insert(begin, end);
}
