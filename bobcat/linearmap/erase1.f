// bool erase(Key const &key)
//
template <typename Key, typename Value>
bool LinearMap<Key, Value>::erase(Key const &key)
{
    auto iter = find(key);
    if (iter == end())
        return false;

    erase(iter);
    return true;
}
