// bool erase(Key const &key)
//
template <typename Key, typename Value, typename Alloc>
void LinearMap<Key, Value, Alloc>::erase(iterator iter)
{
    Base::erase(iter);
}
