//  iterator insert(iterator pos, value_type const &keyValue);

template <typename Key, typename Value, typename Alloc>
typename LinearMap<Key, Value, Alloc>::iterator
    LinearMap<Key, Value, Alloc>::insert(iterator pos, 
              value_type const &keyvalue)
{
    auto iter = find(keyvalue.first);
    if (iter == end())
    {
        push_back(keyvalue);
        iter = iterator(&Base::back());
    }
    return iter;
}
