// std::pair<iterator, iterator> equal_range(Key const &key)

template <typename Key, typename Value>
inline typename LinearMap<Key, Value>::IterPair
        LinearMap<Key, Value>::equal_range(Key const &key)
{
    iterator iter = lower_bound(key);
    return IterPair(iter, iter);
}
