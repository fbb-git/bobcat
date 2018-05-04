// const_iterator upper_bound(Key const &key) const

template <typename Key, typename Value>
inline typename LinearMap<Key, Value>::const_iterator 
        LinearMap<Key, Value>::upper_bound(Key const &key) const
{
    return const_iterator(findPtr(key));
}
