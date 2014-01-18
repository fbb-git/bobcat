//  iterator insert(iterator pos, value_type const &keyValue);

template <typename Key, typename Value, typename Alloc>
template <typename Iterator>
inline void LinearMap<Key, Value, Alloc>::insert(Iterator begin, Iterator end)
{
    for (; begin != end; ++begin)
        insert(*begin);
}
