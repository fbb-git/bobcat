// size_t count(Key const &key) const

template <typename Key, typename Value>
inline size_t LinearMap<Key, Value>::count(Key const &key) const
{
    return find(key) != end();
}
