// size_t count(Key const &key) const

template <typename Key, typename Value, typename Alloc>
inline size_t LinearMap<Key, Value, Alloc>::count(Key const &key) const
{
    return find(key) != end();
}
