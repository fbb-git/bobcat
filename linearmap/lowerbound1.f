// iterator lower_bound(Key const &key)

template <typename Key, typename Value, typename Alloc>
inline typename LinearMap<Key, Value, Alloc>::iterator 
        LinearMap<Key, Value, Alloc>:: lower_bound(Key const &key)
{
    return iterator(findPtr(key));
}
