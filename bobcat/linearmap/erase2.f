// bool erase(Key const &key)
//
template <typename Key, typename Value>
void LinearMap<Key, Value>::erase(iterator iter)
{
    Base::erase(iter);
}
