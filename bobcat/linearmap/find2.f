// const_iterator find(Key const &key) const

template <typename Key, typename Value, typename Alloc>
inline typename LinearMap<Key, Value, Alloc>::const_iterator 
        LinearMap<Key, Value, Alloc>::find(Key const &key) const
{
    return const_iterator(findPtr(key));
}
