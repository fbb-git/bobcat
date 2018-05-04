// bool erase(Key const &key)
//
template <typename Key, typename Value>
void LinearMap<Key, Value>::erase(iterator begin, iterator end)
{
    Base::erase(begin, end);
}
