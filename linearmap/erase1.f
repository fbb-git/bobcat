// bool erase(Key const &key)
//
template <typename Key, typename Value, typename Alloc>
bool LinearMap<Key, Value, Alloc>::erase(Key const &key)
{
    auto iter = find(key);
    if (iter == end())
        return false;

    erase(iter);
    return true;
}
