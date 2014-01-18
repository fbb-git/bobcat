//         Value &at(Key const &key);

template <typename Key, typename Value, typename Alloc>
Value &LinearMap<Key, Value, Alloc>::at(Key const &key)
{
    auto iter = find(key);
    if (iter == end())
        throw std::out_of_range("LinearMap::at");

    return iter->second;
}
