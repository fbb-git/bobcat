// const_iterator lower_bound(Key const &key) const

template <typename Key, typename Value, typename Alloc>
inline typename LinearMap<Key, Value, Alloc>::const_iterator 
        LinearMap<Key, Value, Alloc>::lower_bound(Key const &key) const
{
    return const_iterator(findPtr(key));
}
