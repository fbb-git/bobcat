// iterator lower_bound(Key const &key)

template <typename Key, typename Value>
inline typename LinearMap<Key, Value>::iterator 
        LinearMap<Key, Value>:: lower_bound(Key const &key)
{
    return iterator(findPtr(key));
}
