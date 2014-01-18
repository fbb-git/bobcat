// std::pair<iterator, iterator> equal_range(Key const &key)

template <typename Key, typename Value, typename Alloc>
inline typename LinearMap<Key, Value, Alloc>::IterPair
        LinearMap<Key, Value, Alloc>::equal_range(Key const &key)
{
    iterator iter = lower_bound(key);
    return IterPair(iter, iter);
}
