// iterator find(Key const &key)

template <typename Key, typename Value>
inline typename LinearMap<Key, Value>::iterator 
        LinearMap<Key, Value>:: find(Key const &key)
{
    return iterator(findPtr(key));
}
