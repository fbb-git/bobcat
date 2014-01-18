// std::pair<const_iterator, const_iterator> equal_range(Key const &key) const

template <typename Key, typename Value, typename Alloc>
inline typename LinearMap<Key, Value, Alloc>::ConstIterPair
        LinearMap<Key, Value, Alloc>::equal_range(Key const &key) const
{
    const_iterator iter = lower_bound(key);
    return ConstIterPair(iter, iter);
}
