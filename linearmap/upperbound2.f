// const_iterator upper_bound(Key const &key) const

template <typename Key, typename Value, typename Alloc>
inline typename LinearMap<Key, Value, Alloc>::const_iterator 
        LinearMap<Key, Value, Alloc>::upper_bound(Key const &key) const
{
    return const_iterator(findPtr(key));
}
